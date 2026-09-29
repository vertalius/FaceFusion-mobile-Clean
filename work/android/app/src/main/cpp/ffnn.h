#include "ffnn.h"
#include <android/log.h>

#define LOG_TAG "FFNN"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

namespace ffnn {

NsfwDetector::NsfwDetector() : loaded_(false) {}

NsfwDetector::~NsfwDetector() {}

bool NsfwDetector::load(const std::string& modelPath) {
    loaded_ = true;
    LOGI("NsfwDetector loaded in stub mode (censorship bypassed).");
    return true;
}

float NsfwDetector::predict(const uint8_t* bgrData, int width, int height) {
    // Always return safe score
    return -1.0f;
}

bool NsfwDetector::isNsfw(const uint8_t* bgrData, int width, int height, float threshold) {
    // Censorship check disabled: always false (not NSFW)
    return false;
}

} // namespace ffnn