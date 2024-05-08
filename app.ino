// 引入库
#include <DHT11.h>
#include <FastLED.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// 定义LED引脚和数量
#define LED_PIN 2
#define LED_COUNT 12

// LED类型和颜色顺序
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

// OLED屏幕参数
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C
#define OLED_RESET -1

// 定义DHT11传感器引脚
#define DHT_PIN 4

// 创建一个DHT11对象
DHT11 dht(DHT_PIN);

// 创建一个SSD1306 OLED屏幕对象
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// 创建一个CRGB类型的LED数组
CRGB leds[LED_COUNT];

// 按钮引脚
#define btn 5

// 控制模式变量
int mode = 0;

void setup() {
  // 设置函数，在Arduino启动时运行一次

  // 初始化串口通信
  Serial.begin(9600);

  // 初始化LED条和SSD1306 OLED屏幕
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, LED_COUNT).setCorrection(TypicalLEDStrip);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // 设置屏幕文本属性
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // 设置按钮引脚为输入模式，带上拉电阻
  pinMode(btn, INPUT_PULLDOWN);
}

void loop() {
  // 主循环函数，会持续执行

  // 读取按钮状态
  int status = digitalRead(btn);

  // 检测按钮是否按下，切换模式
  if (status == 0) {
    if (mode == 3) {
      mode = 0;
    } else {
      mode += 1;
    }
  }

  // 输出按钮状态和模式到串口，用于调试
  Serial.print("status: ");
  Serial.print(status);
  Serial.print("     ");
  Serial.println(mode);

  // 更新屏幕和LED灯光
  showScreen(mode);
  light(mode);
}

void showScreen(int mode) {
  // 显示屏函数，用于更新OLED屏幕内容

  // 读取DHT11传感器数据（湿度和温度）
  int humidity = dht.readHumidity();
  int temperature = dht.readTemperature();

  // 清空屏幕
  display.clearDisplay();
  display.setCursor(0, 20);
  
  // 显示湿度
  display.print("Moisture: ");
  display.print(humidity);
  display.println("%");

  // 显示温度
  display.print("Temperature: ");
  display.print(temperature);
  display.println("C");

  // 显示光照模式
  display.print("Light Mode: ");

  // 根据模式值，显示不同的光照模式
  if(mode == 0){
    display.print("Closed");
  }else if (mode == 1){
    display.print("Low");
  }else if (mode == 2){
    display.print("Strong");
  }else if (mode == 3){
    display.print("Warm");
  }

  // 更新屏幕显示
  display.display();
}

void light(int mode) {
  // 控制LED灯光函数

  // 根据模式值，设置LED灯光效果
  if (mode == 0) {
    fill_solid(leds, LED_COUNT, CRGB::Black);
  } else if (mode == 1) {
    fill_solid(leds, LED_COUNT, CRGB(255, 255, 255));
    FastLED.setBrightness(50);
  } else if (mode == 2) {
    fill_solid(leds, LED_COUNT, CRGB(255, 255, 255));
    FastLED.setBrightness(100);
  } else if (mode == 3) {
    fill_solid(leds, LED_COUNT, CRGB::Yellow);
    FastLED.setBrightness(100);
  }

  // 更新LED灯光
  FastLED.show();
}
