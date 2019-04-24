///////////////////////////////////////////
//Group 6 Iris Recognition
//CEG4110 Dr. Bourbakis
//Intro to Software Engineering
//Spring Semester 2019
//Group Members
//Michael Briningstool
//Adam Cone
//Brianna Kreger
//David Reeves
//Joshua Shaw
//Original Source code was obtained from 
//Github user Ekberjan project Iris_Image_Matching
//OpenCV version 2.4.10 library is also used
///////////////////////////////////////////
<<<<<<< HEAD

=======
>>>>>>> c71e5865fd8b82e8b528f8ec083537bb25b98385
#include "stdafx.h"
#include <stdexcept>
#include "pirCircle.h"

namespace Proline
{

	/* Constructor & Destructor */

	pirCircle::pirCircle()
	{
		// nothing to do
	}

	pirCircle::~pirCircle()
	{
		// nothing to do
	}

	pirCircle::pirCircle(const cv::Point & rCenter, int rRadius)
	{
		setCenter(rCenter);
		setRadius(rRadius);
	}


	// ACCESSORS // 
	cv::Point pirCircle::getCenter() const
	{
		return mCenter;
	}

	int pirCircle::getRadius() const
	{
		return mRadius;
	}

	void pirCircle::setCenter(const cv::Point & rCenter)
	{
		mCenter = rCenter;
	}

	void pirCircle::setRadius(int rRadius)
	{
		if (rRadius < 0)
		{
			throw std::runtime_error("pirCircle::setRadius() : Circle with negative radius: " + rRadius);
		}
		mRadius = rRadius;
	}

	void pirCircle::setCircle(const cv::Point & rCenter, int rRadius)
	{
		setCenter(rCenter);
		setRadius(rRadius);
	}

	void pirCircle::setCircle(int rCenterX, int rCenterY, int rRadius)
	{
		setCircle(cv::Point(rCenterX, rCenterY), rRadius);
	}


	// OPERATORS // 
	void pirCircle::drawCircle(cv::Mat & pImage, const cv::Scalar & rColor, int thickness)
	{
		cv::circle(pImage, mCenter, mRadius, rColor, thickness);
	}

	void pirCircle::computeCircleFitting(const std::vector<cv::Point> & rPoints)
	{
		// Compute the average mx and my
		float mx = 0, my = 0;
		for (int p = 0; p < rPoints.size(); p++)
		{
			mx += rPoints[p].x;
			my += rPoints[p].y;
		}
		mx = mx / rPoints.size();
		my = my / rPoints.size();

		// Work in (u, v) space, with u = x - mx and v = y - my
		float u = 0, v = 0, suu = 0, svv = 0, suv = 0, suuu = 0, svvv = 0, suuv = 0, suvv = 0;

		// Build some sums
		for (int p = 0; p < rPoints.size(); p++)
		{
			u = rPoints[p].x - mx;
			v = rPoints[p].y - my;
			suu += u * u;
			svv += v * v;
			suv += u * v;
			suuu += u * u * u;
			svvv += v * v * v;
			suuv += u * u * v;
			suvv += u * v * v;
		}

		// These equations are demonstrated in paper from R.Bullock (2006)
		float uc = 0.5 * (suv * (svvv + suuv) - svv * (suuu + svvv)) / (suv * suv - suu * svv);
		float vc = 0.5 * (suv * (suuu + suvv) - suu * (svvv + suuv)) / (suv * suv - suu * svv);

		// Circle parameters
		setCenter(cv::Point(uc + mx, vc + my));
		setRadius((int)(std::sqrt(uc*uc + vc*vc + (suu + svv) / rPoints.size())));

	}

} // end of namespace
