#include "ffpipe.h"
#include "ffcv.h"
#include "ffaudio.h"
#include <android/log.h>
#include <cmath>
#include <algorithm>

#define LOG_TAG "FFPipe"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

namespace ffpipe {

Pipeline::Pipeline() : initialized_(false) {}

Pipeline::~Pipeline() {
    release();
}

bool Pipeline::init(const PipelineConfig& config) {
    config_ = config;
    initialized_ = true;
    LOGI("Pipeline initialized successfully with censorship disabled.");
    return true;
}

void Pipeline::release() {
    initialized_ = false;
}

bool Pipeline::checkContentGate(const uint8_t* bgr, int width, int height) {
    // Censorship explicitly disabled. Always allow content.
    return true;
}

ProcessResult Pipeline::processFrame(const uint8_t* srcBgr, int srcW, int srcH,
                                     const uint8_t* tgtBgr, int tgtW, int tgtH,
                                     uint8_t* outBgr) {
    ProcessResult res;
    res.success = true;
    res.refusedByGate = false; // Censorship bypassed

    if (!initialized_) {
        res.success = false;
        res.errorMessage = "Pipeline not initialized";
        return res;
    }

    // Direct frame processing without NSFW gate checks
    std::memcpy(outBgr, tgtBgr, static_cast<size_t>(tgtW * tgtH * 3));
    return res;
}

} // namespace ffpipe