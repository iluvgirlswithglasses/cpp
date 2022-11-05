---
title: "Free Contest 101 - Sumfrac"
author: "iluvgirlswithglasses"
date: "Nov-5-2022"
geometry: margin=2cm
output: 
  pdf_document: 
    latex_engine: xelatex
fontsize: 12pt
---

## Nhắc nhở:

  - $f(N)$: Số nguyên tố nhỏ nhất $> N$
  - $g(N)$: Số nguyên tố lớn nhất $\leq N$
  - Vì khoảng cách tối đa giữa hai số nguyên tố liền kề có giá trị không quá $10^9$ là 288 (https://en.wikipedia.org/wiki/Prime_gap), ta có thể tìm giá trị $f(N)$ và $g(N)$ của một số $N$ cho trước trong một khoảng thời gian rất ngắn.

## Lời giải:

Gọi $K = f(K) - 1$, ta có đẳng thức sau:

$$\sum_{i=2}^{K}\frac{1}{f(i) \times g(i)} = \
  \frac{1}{2 \times 3} + \frac{2}{3 \times 5} + \frac{2}{5 \times 7} + ... + \frac{x}{g(K) \times f(K)} = \
  \frac{K - 1}{2 \times f(K)}$$

Vậy, bài toán ban đầu có thể được viết thành:

$$\sum_{i=2}^{K}\frac{1}{f(i) \times g(i)} + \sum_{i=g(N)}^{N}\frac{1}{f(i) \times g(i)} = \ 
  \frac{K - 1}{2 \times f(K)} + \frac{N - K}{f(N) \times g(N)}$$

Mà $f(K) = g(N)$, nên khi quy đồng, ta có kết quả của bài toán là:

$$\frac{(K - 1) \times f(N) + (N - K) \times 2}{2 \times f(N) \times g(N)}$$
