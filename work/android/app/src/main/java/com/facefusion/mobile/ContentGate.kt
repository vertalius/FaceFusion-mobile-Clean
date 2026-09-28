package com.facefusion.mobile

import android.content.Context
import android.net.Uri
import androidx.compose.runtime.mutableStateOf

object ContentGate {
    val isReady = mutableStateOf(true)

    enum class Verdict {
        ALLOW, BLOCK, ERROR
    }

    fun prepare(context: Context) {
        isReady.value = true
    }

    fun inspectStill(context: Context, source: Uri): Verdict {
        return Verdict.ALLOW
    }

    fun inspectClip(context: Context, source: Uri, onProgress: (Float) -> Unit): Verdict {
        return Verdict.ALLOW
    }
}
