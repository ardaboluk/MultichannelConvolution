/*#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace cv;

int main() {

	int borderSize = 1;
	float kernel[3][3][3] = { { {1,0,-1},{2,0,-2},{1,0,-1} }, { {1,2,1},{2,4,2},{1,2,1} }, { {1,1,1},{1,1,1},{1,1,1} } };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			kernel[1][i][j] /= 16;
			kernel[2][i][j] /= 9;
		}
	}

	Mat imgOriginal = imread("image_for_part_2.jpg");
	Size originalSize = imgOriginal.size();
	Mat imgBordered(originalSize.height + borderSize * 2, originalSize.width + borderSize * 2, imgOriginal.type());
	Mat imgFiltered(originalSize, imgOriginal.type());

	copyMakeBorder(imgOriginal, imgBordered, borderSize, borderSize, borderSize, borderSize, BORDER_REFLECT);

	for (int currentRow = 1; currentRow < imgBordered.rows - 1; currentRow++) {
		for (int currentCol = 1; currentCol < imgBordered.cols - 1; currentCol++) {
			float sumb = 0, sumg = 0, sumr = 0;
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					Vec3b bgrPixel = imgBordered.at<Vec3b>(currentRow + i, currentCol + j);
					sumb += bgrPixel[0] * kernel[0][i + 1][j + 1];
					sumg += bgrPixel[1] * kernel[1][i + 1][j + 1];
					sumr += bgrPixel[2] * kernel[2][i + 1][j + 1];
				}
			}
			if (sumb < 0) {
				sumb = 0;
			}else if (sumb > 255) {
				sumb = 255;
			}
			if (sumg < 0) {
				sumg = 0;
			}else if (sumg > 255) {
				sumg = 255;
			}
			if (sumr < 0) {
				sumr = 0;
			}else if (sumr > 255) {
				sumr = 255;
			}
			imgFiltered.at<Vec3b>(currentRow - 1, currentCol - 1)[0] = (uchar)sumb;
			imgFiltered.at<Vec3b>(currentRow - 1, currentCol - 1)[1] = (uchar)sumg;
			imgFiltered.at<Vec3b>(currentRow - 1, currentCol - 1)[2] = (uchar)sumr;
		}
	}
	
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", imgFiltered);
	imwrite("./filtered.jpg", imgFiltered);
	waitKey(0);

	return 0;
}*/