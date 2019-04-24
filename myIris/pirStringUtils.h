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
<<<<<<< HEAD
///////////////////////////////////////////
=======
////////////////////////////////////////////
>>>>>>> c71e5865fd8b82e8b528f8ec083537bb25b98385
#ifndef PIR_STRING_UTILS_H
#define PIR_STRING_UTILS_H

#include <stdexcept>
#include <iostream>
#include <string>
#include <algorithm> // for lowercase/uppercase conversions
#include <sstream>

namespace Proline
{
	/** Strings handler.
	* Contains some useful functions for strings.
	*/
	class pirStringUtils
	{
	public:

		/** Default constructor. */
		pirStringUtils()
		{
			// Do nothing
		}

		/** Default destructor. */
		~pirStringUtils()
		{
			// Do nothing
		}


		/** Convert any basic type into string.
		* @param rData The data to convert
		* @return A string
		*/
		template < typename T > std::string toString(const T & rData)
		{
			std::ostringstream oss;
			oss << rData;
			return oss.str();
		}

		/** Convert a string into any basic type.
		* @param rString A string
		* @return Template T
		*/
		template < typename T > T fromString(const std::string & rString);


		/** Remove leading and trailing spaces and/or tabs.
		* @param rString A string
		* @return A string
		*/
		std::string trim(const std::string & rString)
		{
			std::string s = rString.substr(0, rString.find_last_not_of("\r\n") + 1);
			int first = s.find_first_not_of(" \t");
			if (first != std::string::npos)
				return s.substr(first, s.find_last_not_of(" \t") - first + 1);
			else
				return "";
		}


		/** Convert BackSlashes into slashes
		* @param rString A string
		* @return A string
		*/
		std::string convertSlashes(const std::string & rString)
		{
			std::string out = rString;

			for (int i = 0; i < rString.size(); i++)
			{
				if (rString[i] == '\\')
				{
					out[i] = '/';
				}
			}
			return out;
		}


		/** Convert to uppercase.
		* @param rString A string
		* @return A string
		*/
		std::string toUpper(const std::string & rString)
		{
			std::string out = rString;
			std::transform(out.begin(), out.end(), out.begin(), ::toupper);
			return out;
		}

		/** Convert to lowercase.
		* @param rString A string
		* @return A string
		*/
		std::string toLower(const std::string & rString)
		{
			std::string out = rString;
			std::transform(out.begin(), out.end(), out.begin(), ::tolower);
			return out;
		}

		/** Extract the filename from a full path string
		* @param rFullPath A string
		* @return A string
		*/
		std::string extractFileName(const std::string & rFullPath)
		{
			std::string filename = rFullPath;
			int pos = filename.find_last_of("/");
			if (pos != std::string::npos) filename = filename.substr(pos);
			return filename.substr(0, filename.find_last_of("."));
		}

	}; // End of class



	// Definition of fromString
	template < typename T >
	T pirStringUtils::fromString(const std::string & rString)
	{
		std::istringstream iss(rString);
		T out;
		if (!(iss >> out))
			throw std::runtime_error("Cannot convert " + rString + " into basic type");
		return out;
	}

	// Specialization of function fromString() for boolean
	template < >
	inline bool pirStringUtils::fromString<bool>(const std::string & rString)
	{
		std::string s = trim(toLower(rString));
		if (s == "yes" || s == "true" || s == "on" || s == "y" || s == "1")
			return true;
		else if (s == "no" || s == "false" || s == "off" || s == "n" || s == "0")
			return false;
		else
			throw std::runtime_error("Cannot convert " + rString + " into boolean");
	}

} // End of namespace



#endif

