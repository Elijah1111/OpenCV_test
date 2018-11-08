#include <opencv2/opencv.hpp>

using namespace cv;
int main( int argc, char** argv )
{
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Initialize Zone~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	Mat src;//Mat aka a matrix that represents the image
	Mat gray;//a mat to store a gray scale of original

	src = imread("ham.jpg");//read the image in argument 1


	if( argc != 2 || !src.data )//Can you read the image?
	{
		printf( "No image data \n" );
		return -1;
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Initialize Zone~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Split Zone~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	Mat blue (src.rows, src.cols, CV_8UC3);
	Mat green (src.rows, src.cols, CV_8UC3);
	Mat red (src.rows, src.cols, CV_8UC3);

	for (int i = 0; i < src.rows; i ++){//loops through the image and assigns the vector of color
		for (int j = 0; j < src.cols; j ++){//this part grabs the vector that is the color 3 times then assigns part of it to be 0
			Vec3b temp_blue;
			temp_blue=src.at<Vec3b>(i,j); temp_blue[1] = 0; temp_blue[2] = 0;//only blue

			Vec3b temp_green;
			temp_green=src.at<Vec3b>(i,j); temp_green[0] = 0; temp_green[2] = 0;//only green

			Vec3b temp_red;
			temp_red=src.at<Vec3b>(i,j); temp_red[0] = 0; temp_red[1] = 0;//only red

			blue.at<Vec3b>(i,j) = temp_blue;//assign blue vector to image
			green.at<Vec3b>(i,j) = temp_green;//assign green vector to image
			red.at<Vec3b>(i,j) = temp_red;//assign red vector to image
		}
	}

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Split Zone~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Manipulation Zone~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	cvtColor( src, gray, CV_BGR2GRAY );//convert to greyscale
	rectangle(gray,Point(0,0),Point(100,100),Scalar(255,0,0));



	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Manipulation Zone~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Display Zone~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	imshow( "Display Original", src );
	imshow( "Display Gray", gray );
	imshow( "Display Blue", blue );//blue
	imshow( "Display Green", green );//green
	imshow( "Display Red", red );//red

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Display Zone~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




	waitKey(0);//wait


	return 0;
}
