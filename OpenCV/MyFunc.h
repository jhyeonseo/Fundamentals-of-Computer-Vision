#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cmath>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "utils.h"

using namespace cv;
using namespace cv::dnn;

struct IMAGE
{
	Mat ref = imread("../data/pictures/original/ref.bmp", 1);
	Mat tar = imread("../data/pictures/original/tar.bmp", 1);
	Mat base = imread("../data/pictures/original/lecture3.bmp", 1);
	Mat compare = imread("../data/pictures/original/compare1.bmp", 1);
	Mat compare2 = imread("../data/pictures/original/compare2.bmp", 1);
	Mat cat = imread("../data/pictures/original/cat1.jpg", 1);
	Mat dog = imread("../data/pictures/original/dog1.jpg", 1);
	Mat text = imread("../data/pictures/original/text1.jpg", 1);
};
struct VIDEO
{
	VideoCapture frog = VideoCapture("../data/videos/original/frog1.mp4");
	VideoCapture people = VideoCapture("../data/videos/original/people1.mp4");
	VideoCapture ship = VideoCapture("../data/videos/original/ship1.mp4");
	VideoCapture bloom = VideoCapture("../data/videos/original/bloom1.mp4");
	VideoCapture surfing = VideoCapture("../data/videos/original/surfing1.mp4");
};
struct FEATURE
{
	// Basic information
	Mat image;
	Mat grad;
	Mat magnitude;
	Mat phase;
	
	// Feature information
	std::vector<Point> edge;
	std::vector<Point> corner;
	double* histogram;
};

class CVLAB
{
private:
	std::vector<FEATURE>storage;

public:
	// 사용의 편리성을 위한 함수
	CVLAB();
	void Insert(Mat img);
	//void Editor();
	void Print(Mat input);

	// Application을 위한 함수
	Mat EDGE(Mat input);
	Mat CORNER(Mat input, int option = 0);   // Option 0: Harris
	Mat LINKCORNER(Mat input1, Mat input2);
	Mat MYORB(Mat img1, Mat img2, Size window);

	// 이미지 feature 추출을 위한 함수
	void PixelValue(Mat img, int x, int y);
	double* HOG(Mat input, Size block, int interval = 8, int binsize = 9);  // Histograms of oriented gradients
	double* HOG(Mat input, Size block, std::vector<Point> point, int binsize = 9);
	std::vector<Point> HARRIS(Mat input, Size window, double threshold = 0.015);     // Corner point detection

	// 이미지 변환을 위한 함수
	Mat GRAY(Mat img);
	Mat GRAY(Mat img, Point center, Size size);
	Mat RESIZE(Mat img, Size size, int option = 0);
	Mat RESIZE(Mat img, double scalor, int option = 0);
	Mat ROTATE(Mat img, double angle, int option = 0);
	Mat COMBINE(Mat img1, Mat img2);

	// 수학적 처리를 위한 함수
	Mat CONV(Mat input, Mat filter);
	Mat GRADIENT(Mat input);
	Mat MAGNITUDE(Mat gradient);
	Mat PHASE(Mat gradient);
	Mat NORMALIZE(Mat input, double range = 0);  // range 0: L2 normalization
	void NORMALIZE(double* input, double inputsize, double range = 0);
	double DISTANCE(double* input1, double* input2, int size);
};
void MOUSEINF(int event, int x, int y, int flags, void* MouseData);

