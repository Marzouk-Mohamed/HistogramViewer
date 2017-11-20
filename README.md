# HistogramViewer
A mini application on Qt + OpenCV to display image histograms 

# Prerequisities 

In order to compile this source code, Qt Creator 4+ is needed as well as OpenCV installed.

Then, the TestApp.pro file needs to be configured. More particulary, two changes in that file must be made:

 - INCLUDEPATH += <path_to_opencv_headers_in_your_file_system>
 - LIBS += -L<path_to_opencv_libraries_in_your_file_system>

The source code is ready to be compiled on Qt Creator.
