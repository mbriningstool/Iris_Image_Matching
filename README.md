# **Iris-Verification**
** C++ based iris image verification code using OpenCV **

This iris verification algorithm is originally based on *A Biometric System for Iris OSIRIS version 4.1* developed by Telecom Sud Paris. You may access the original version here: 

http://svnext.it-sudparis.eu/svnview2-eph/ref_syst/Iris_Osiris_v4.1/

**Before you use: *

1. Make sure you have installed OpenCV on your computer, since the code relies on it.

2. Copy those header files under folders named `opencv` and `opencv2` from your installed OpenCV location to `x64/Release/HeaderFiles/` of the solution, or change the opencv header file source directly from the *Solution Properties -> C/C++ -> General -> Additional Include Directories* to point towards your original `opencv` and `opencv2` paths, such as `C:\OpenCV-2.4.10\build\include\opencv` and `C:\OpenCV-2.4.10\build\include\opencv2`. 

3. Create a folder as `x64/Release/Libs/` and copy those OpenCV lib files under it, or change the related solution property, by changing *Solution Property -> Linker -> General -> Additional Library Directories* to your original OpenCV lib path, such as `C:\OpenCV-2.4.10\build\x64\vc12\lib`. 

4. For the whole description of the iris matching algorithm and processes, take reference for the following documentation: 

http://svnext.it-sudparis.eu/svnview2-eph/ref_syst/Iris_Osiris_v4.1/doc/

5. The main code reads two iris images, and performs matching. The final matching result is a score between 0.0 and 1.0, where 0.0 means the two iris images are totally different, while 1.0 means they are exactly the same. 

6. The parameters for Gabor filters used are saved in those files under `PirisParam` folder.  

7. You can change relevant contents of file `configuration.ini` for other purposes, such as writing out the matching score result into a file, etc. Read the above mentioned documentation for further details. 

8. This distribution is subject to GNU GENERAL PUBLIC LICENSE. 


Best wishes, 

Ekberjan 
