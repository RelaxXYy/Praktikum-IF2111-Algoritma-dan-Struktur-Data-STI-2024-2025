#include <stdio.h>
#include "boolean.h"
#include "rectangle.h"

RECTANGLE MakeRectangle(float width, float height){
    RECTANGLE R;
    Width(R) = width;
    Height(R) = height;
    return R;
}


void readRectangle(RECTANGLE *R){
    scanf("%f %f", &Height(*R), &Height(*R));
}

void printRectangle(RECTANGLE R){
    printf("R(%.2fx%.2f)\n", Width(R), Height(R));
}

boolean isSquare(RECTANGLE R){
    return (Width(R) == Height(R));
}

boolean isNotSquare(RECTANGLE R){
    return (Width(R) != Height(R));
}
float area(RECTANGLE R){
    return (Width(R) * Height(R));
}

float perimeter(RECTANGLE R){
    return (2 * (Width(R) + Height(R)));
}

void swap(RECTANGLE *R){
    float temp = Width(*R);
    Width(*R) = Height(*R);
    Height(*R) = temp;
}

void add(RECTANGLE *R, float deltaWidth, float deltaHeight){
    Width(*R) += deltaWidth;
    Height(*R) += deltaHeight;
}

RECTANGLE plusRectangle(RECTANGLE R, float deltaWidth, float deltaHeight){
    Width(R)+= deltaWidth;
    Height(R)+= deltaHeight;
    return R;
}

