package com.facefusion.mobile

import android.graphics.Bitmap
import android.net.Uri
import java.io.File

/**
 * One queued target — roadmap 14.
 *
 * The batch is ONE SOURCE, MANY TARGETS. That is the shape a user asks for ("put my face on
 * these twelve clips") and it is the shape the warm pipeline already has: `setSource` is
 * called once and every target reuses it, so the models and the identity are paid for once
 * instead of twelve times.
 */
data class BatchItem(
    val uri: Uri,
    val name: String,
    val state: BatchState = BatchState.Waiting,
    /** Where it landed. Null until it succeeds. */
    val output: File? = null,
    /** Detail message or error description. */
    val detail: String? = null,
    /** A small frame from [output], for the queue row. */
    val thumb: Bitmap? = null,
    /** Where this clip landed in the gallery, once it has been saved. */
    val savedUri: Uri? = null,
)

/**
 * Where one queued target got to.
 */
enum class BatchState {
    Waiting,
    Running,
    Done,
    Refused, // Retained for backwards compatibility with UI state mapping
    Failed,
    Skipped
}