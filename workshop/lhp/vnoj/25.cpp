
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Jan 14 15:21:58 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <bits/stdc++.h>
using namespace std;

/*
ý tưởng:

gọi các nhà là cách đỉnh,
đường đi từ nhà này sang nhà liền kề là cạnh

1.	dùng sweepline để lấy cạnh
2.	từ cạnh, dựng đồ thị, tìm cầu trong O(V+E). 
	các bridge tìm được là các đường độc đạo
3.	trường hợp không tìm được bridge nào, ngắt chương trình và xuất ra -1 ngay lập tức
4.	giả sử xóa hết các đường độc đạo, sẽ chia đồ thị thành các group.
	tính số nhà có trong từng group
5.	các group bây giờ tạo thành 1 cây. dfs từ edge của cây sang edge còn lại
	khi này, sẽ có đc 1 mảng dp[], 
	trong đó dp[i] = tổng của các group [0:i] 
6.	xóa lần lượt các bridge, rồi kiểm tra xem chênh lệch số nhà 2 bên cầu là bao nhiêu
	hiệu nhỏ nhất của bước làm trên là đáp án bài toán


duma nó dài.... chắc làm k kịp rồi
*/

/**
 * @ defs
 * */

/**
 * @ vars
 * */

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	return 0;
}
