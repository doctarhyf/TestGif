#include "widget.h"
#include "ui_widget.h"
#include <vector>
#include <cstdint>
#include <gif.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    int width = 100;
    int height = 200;
    std::vector<uint8_t> black(width * height * 4, 0);
    std::vector<uint8_t> white(width * height * 4, 255);
    std::vector<uint8_t> red(width * height * 4, 64);
    std::vector<uint8_t> green(width * height * 4, 128);

    auto fileName = "bwgif.gif";
    int delay = 100;
    GifWriter g;
    GifBegin(&g, fileName, width, height, delay);
    GifWriteFrame(&g, black.data(), width, height, delay);
    GifWriteFrame(&g, white.data(), width, height, delay);
    GifWriteFrame(&g, red.data(), width, height, delay);
    GifWriteFrame(&g, green.data(), width, height, delay);
    GifEnd(&g);



}

Widget::~Widget()
{
    delete ui;
}
