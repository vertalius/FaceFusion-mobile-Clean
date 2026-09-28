name: Build APK
on:
  workflow_dispatch:

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4

      - name: set up JDK 17
        uses: actions/setup-java@v4
        with:
          java-version: '17'
          distribution: 'temurin'
          cache: gradle

      - name: Install Android NDK & CMake (для сборки C++ кода)
        run: |
          echo "y" | $ANDROID_HOME/cmdline-tools/latest/bin/sdkmanager --install "ndk;25.1.8937393" "cmake;3.22.1"

      - name: Grant execute permission for gradlew
        run: chmod +x work/android/gradlew

      - name: Build with Gradle
        run: |
          cd work/android
          ./gradlew assembleDebug

      - name: Upload APK
        uses: actions/upload-artifact@v4
        with:
          name: facefusion-uncensored
          path: work/android/app/build/outputs/apk/debug/app-debug.apk
