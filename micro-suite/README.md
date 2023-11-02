# How to build micro benchmarks.

1. Set up your toolchain for WASM (see AndroidWasm/wasm_ndk).

2. Configure ANDROID_NDK_HOME and ANDROID_CLANG_TOOLCHAIN environment variables
   accordingly.

3. Attach your android test device so that `adb` can see it.

4. Run

   ```
   ./compile-and-push-all
   ```

5. Log into device using `adb shell`:

   ```
   adb shell
   cd /data/local/tmp
   ```

6. Run the timing script on device:

   ```
   ./time-all 2>time-all.out
   ```

7. On host, fetch `time-all.out`:

   ```
   adb pull /data/local/tmp/time-all.out
   ```

   You can now run `size-all` locally:

   ```
   ./size-all >size-all.out
   ```

   Ten process both outputs using the awk script:

   ```
   awk -f make-csv.awk time-all.out size-all.out >numbers.csv
   ```
