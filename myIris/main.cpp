///////////////////////////////////////////
//Group 6 Iris Recognition
//CEG4110 Dr. Bourbakis
//Intro to Software Engineering
//Original Source code was obtained from 
//Github user Ekberjan project Iris_Image_Matching
//OpenCV version 2.4.10 library is also used
///////////////////////////////////////////

// myIris.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Iris\pirManager.h"

int _tmain(int argc, _TCHAR* argv[])
{
	std::string path = "\\Images\\";
	cv::Mat genImage = cv::imread(path + "\\1.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	cv::Mat testImage = cv::imread(path + "\\2.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	try
	{
		Proline::pirManager pir;
		pir.loadConfiguration("C:\\Users\\mbrin\\Documents\\GitHub\\Iris_Image_Matching\\x64\\Release\\Configuration.ini");		
		pir.run( genImage , testImage , "1.jpg" , "2.jpg" );
		std::cout << "matching score: " << pir.getScore() << std::endl;

	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	

	return 0;
}

