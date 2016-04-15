#ifndef ROOT_FILTER_H
#define ROOT_FILTER_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>

#include <vector>

#include "feature_map.h"
#include "bounding_box.h"
#include <feature_map_svm.h>

#define OBJECT 1
#define NOT_OBJECT -1

class RootFilter
{
public:
    RootFilter(cv::Size filterSize, std::string svm_file);
    void processFeatureMap(const FeatureMap& map, std::vector<BoundingBox>& detectedObjects, int stride=1) const;
    cv::Size  getFilterSize();
private:
    cv::Size filterSize;
    FeatureMapSVM svm;
    float classify(const FeatureMap& map, bool returnDFVal=false) const;
};

#endif
