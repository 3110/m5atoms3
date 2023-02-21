# 自分用 AtomS3/Lite ライブラリ

## コンパイル方法

[PlatformIO IDE](https://platformio.org/platformio-ide)環境でコンパイルする。AtomS3 の場合は`m5atoms3`，AtomS3 Lite の場合は`m5atom-lite`を環境として設定する。

| 環境名          | 定義名                   |
| --------------- | ------------------------ |
| `m5atoms3`      | `-DTARGET_M5ATOMS3`      |
| `m5atoms3-lite` | `-DTARGET_M5ATOMS3_LITE` |

ESP32S3 の場合，シリアルコンソールに表示する際に何秒か遅延させないと表示されないので，`STARTUP_SERIAL_DELAY_MS`で遅延させる秒数（マイクロ秒）を指定する。デフォルトは`build_flags`に指定している 5000 ミリ秒になっている。

2023 年 2 月 22 日時点で AtomS3 Lite にファームウェアをダウンロードする場合，esptool v4.3 より新しいバージョンを使用するとダウンロードに失敗する不具合がある（参考：[Won't upload program fully - stops uploading at random percentages (ESPTOOL-622)](https://github.com/espressif/esptool/issues/842)）ため，`platform_packages`で v4.3 を使うように明示的に指定している。
