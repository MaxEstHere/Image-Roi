
#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>

IplImage* image = 0;

int main(int argc, char* argv[])
{
	//take image
	char filename = argc >= 2 ? argv[1] : "Image0.jpg";
	image = cvLoadImage(filename, 1);
	prinf("[i] image: %s\n", filename);
	assert(image != 0);

	//set windows
	cvNamedWindow("origin", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("roi", CV_WINDOW_AUTOSIZE);

	//set roi size
	int x = argc >=3 ? atoi(argv[2]) : 40;
	int y = argc >=4 ? atoi(argv[3]) : 20;
	int height >= 5 ? atoi(argv[4]) : 100;
	int width >= 6 ? atoi(argv[5]) : 100;
	int add >= 7 ? atoi(argv[6]) : 200;

	//show image 
	cvShowImage("origin", image);
	//set RoI
	cvSetImageRoi(image, cvRect(x, y, width, height));
	cvAddS(image, cvScalar(add), image);
	//reset RoI
	cvResetImageRoi(image);
	//show image
	cvShowImage("roi", image);

	cvWaitKey(0);

    // release resourses
	cvReleaseImage(&image);
	cvDestroyAllWindows();
	return 0;
}