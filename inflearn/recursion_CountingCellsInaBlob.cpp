// Counting Cells in a Blob
// 픽셀 (x,y)가 포함된 Blob의 크기
// (x, y)가 포함되지 않는 경우에는 0

/*
현재 픽셀이 속한 blob의 크기를 카운트하려면
	현재 픽셀이 image color가 아니라면
		0을 반환한다
	현재 픽셀이 image color라면
		먼저 픽셀을 카운트한다.
		현재 픽셀이 중복 카운트되는 것을 방지하기 위해 다른 색으로 칠한다. (visited)
		현재 픽셀이 이웃한 모든 픽셀들에 대해서 (탐색방향은 시계방향) 
			그 픽셀이 속한 blob의 크기를 카운트하여 카운터에 더해준다.
		카운터를 반환한다.

(sudeo code)
if the pixel (x, y) is outside the grid
	result = 0;
else if the pixel (x, y) is not an image pixel or already counted
	result = 0;
else
	set the color of the pixel (x, y) to a red color; (visited)
	the result is 1 plus the number or cells in each piece of 
	the blob that includes a nearest neighbour;


*/

#include <stdio.h>

int N = 8;
int grid[8][8] = {
	{ 1, 0, 0, 0, 0, 0, 0, 1 },
	{ 0, 1, 1, 0, 0, 1, 0, 0 },
	{ 1, 1, 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 0 },
	{ 1, 0, 0, 0, 1, 0, 0, 1 },
	{ 0, 1, 1, 0, 0, 1, 1, 1 },
};
int backgroud = 0;
int image = 1;
int visited = 2;

int countCells(int x, int y){
	int result;
	if (x < 0 || x >= N || y < 0 || y >= N)
		return 0;
	else if ((grid[x][y] != image))
		return 0;
	else{
		grid[x][y] = visited;
		return  1 + countCells(x - 1, y + 1) + countCells(x, y + 1)
			+ countCells(x + 1, y + 1) + countCells(x - 1, y)
			+ countCells(x + 1, y) + countCells(x - 1, y - 1)
			+ countCells(x, y - 1) + countCells(x + 1, y - 1);
	}
}

int main(){
	int inputX = 3;
	int inputY = 5;

	printf("%d\n", countCells(inputX, inputY));

	return 0;
}