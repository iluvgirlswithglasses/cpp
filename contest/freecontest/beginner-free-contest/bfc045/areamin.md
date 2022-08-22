---
title: "areamin.cpp"
author: "iluvgirlswithglasses"
date: "Aug-22-2022"
geometry: margin=2cm
output: 
  pdf_document: 
    latex_engine: xelatex
fontsize: 12pt
---

## Solution

Gọi:  
- $a$: số hình vuông  
- $b$: số hình tròn  
- $x$: chiều rộng hình vuông  
- $y$: bán kính hình tròn  

Ta có:  
$n = 4ax + 2b\pi y \iff y = \dfrac{n - 4ax}{2b\pi}$  

Ta lại có:  
$S = ax^2 + b\pi y^2$  
$= ax^2 + b\pi (n - 4ax)^2 \dfrac{1}{4b^2\pi^2}$  
$= ax^2 + \dfrac{1}{4b\pi}(n^2 + 16a^2x^2 - 8nax)$  
$= (a + \dfrac{4}{b\pi})x^2 - \dfrac{2}{b\pi}nax + C$  

Phương trình bậc 2 dạng $y = ax^2 + bx + c$ có đạo hàm $y' = ax + b$ đạt cực trị tại $x = -\dfrac{b}{a}$  

$\implies S$ đạt cực tiểu tại: $x = \dfrac{\dfrac{2}{b\pi}na}{2a + \dfrac{8}{b\pi}a^2}$  

Nhân $\dfrac{b\pi}{2a}$ cho tử và mẫu  

$\implies x = \dfrac{n}{b\pi + 4a}$  

Suy ra đáp án bài toán là $4x$
