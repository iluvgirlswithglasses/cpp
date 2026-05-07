#include "softmax.h"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

static FILE *input_file;
static FILE *output_file;
static FILE *log_file;
static std::vector<double> all_logits;
static std::vector<double> all_values;
static std::vector<double> expected_results;
static int current_batch;
static int total_batches;
static bool failed;
enum Phase { MAY_GET, MAY_SUBMIT, DONE };
static Phase phase;

int get_batch(double *logits, double *values) {
    if (phase == MAY_SUBMIT) {
        if (log_file) {
            fprintf(log_file, "PROTOCOL ERROR: get_batch() called before submit() for batch %d\n", current_batch);
        }
        fprintf(stderr, "Protocol error: must call submit() before next get_batch() (batch %d)\n", current_batch);
        failed = true;
        return 0;
    }
    if (phase == DONE || current_batch >= total_batches) {
        phase = DONE;
        return 0;
    }

    current_batch++;
    int base = (current_batch - 1) * 8;
    for (int i = 0; i < 8; i++) {
        logits[i] = all_logits[base + i];
        values[i] = all_values[base + i];
    }

    phase = MAY_SUBMIT;

    if (log_file) {
        fprintf(log_file, "get_batch() -> batch %d\n", current_batch);
        fprintf(log_file, "  logits:");
        for (int i = 0; i < 8; i++) fprintf(log_file, " %.6f", logits[i]);
        fprintf(log_file, "\n  values:");
        for (int i = 0; i < 8; i++) fprintf(log_file, " %.6f", values[i]);
        fprintf(log_file, "\n");
    }

    return current_batch;
}

void submit(double result) {
    if (phase != MAY_SUBMIT) {
        if (log_file) {
            fprintf(log_file, "PROTOCOL ERROR: submit() called without prior get_batch()\n");
        }
        fprintf(stderr, "Protocol error: must call get_batch() before submit()\n");
        failed = true;
        return;
    }

    double expected = expected_results[current_batch - 1];
    double error = fabs(result - expected);
    bool correct = (error <= 1e-4);

    if (log_file) {
        fprintf(log_file, "submit(%.15e) -> expected %.15e, error %.2e -> %s\n",
                result, expected, error, correct ? "ACCEPTED" : "WRONG ANSWER");
    }

    if (!correct) failed = true;
    phase = MAY_GET;
}

static std::string derive_output_path(const char *input_path) {
    std::string path(input_path);
    size_t pos = path.rfind("input");
    if (pos != std::string::npos) {
        path.replace(pos, 5, "output");
        return path;
    }
    pos = path.rfind('/');
    if (pos != std::string::npos) {
        return path.substr(0, pos + 1) + "output" + path.substr(pos + 1);
    }
    return "output.txt";
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file> [output_file] [log_file]\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Cannot open input file: %s\n", argv[1]);
        return 1;
    }

    std::string output_path;
    std::string log_path = "interaction.log";

    if (argc >= 3 && std::string(argv[2]).find("output") != std::string::npos) {
        output_path = argv[2];
        if (argc >= 4) log_path = argv[3];
    } else if (argc >= 3) {
        log_path = argv[2];
    }

    if (output_path.empty()) {
        output_path = derive_output_path(argv[1]);
    }

    output_file = fopen(output_path.c_str(), "r");
    if (!output_file) {
        fprintf(stderr, "Cannot open output file: %s\n", output_path.c_str());
        fprintf(stderr, "Provide output file as 2nd argument or place it alongside input.\n");
        fclose(input_file);
        return 1;
    }

    log_file = fopen(log_path.c_str(), "w");

    failed = false;
    current_batch = 0;
    phase = MAY_GET;

    if (fscanf(input_file, "%d", &total_batches) != 1) {
        fprintf(stderr, "Error reading Q\n");
        return 1;
    }

    all_logits.resize(total_batches * 8);
    all_values.resize(total_batches * 8);
    expected_results.resize(total_batches);

    for (int b = 0; b < total_batches; b++) {
        int base = b * 8;
        for (int i = 0; i < 8; i++) {
            if (fscanf(input_file, "%lf", &all_logits[base + i]) != 1) {
                fprintf(stderr, "Error reading logits for batch %d\n", b + 1);
                return 1;
            }
        }
        for (int i = 0; i < 8; i++) {
            if (fscanf(input_file, "%lf", &all_values[base + i]) != 1) {
                fprintf(stderr, "Error reading values for batch %d\n", b + 1);
                return 1;
            }
        }
    }

    for (int b = 0; b < total_batches; b++) {
        if (fscanf(output_file, "%lf", &expected_results[b]) != 1) {
            fprintf(stderr, "Error reading expected result for batch %d\n", b + 1);
            return 1;
        }
    }

    if (log_file) {
        fprintf(log_file, "=== Q=%d ===\n", total_batches);
    }

    solve(total_batches);

    if (log_file) {
        fprintf(log_file, "\n=== FINAL RESULT: %s ===\n", failed ? "WRONG ANSWER" : "ACCEPTED");
        fclose(log_file);
    }

    fclose(input_file);
    fclose(output_file);
    return failed ? 1 : 0;
}
