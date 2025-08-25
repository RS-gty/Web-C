//
// Created by RSgty on 25-8-26.
//
#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>
#include <numbers>
#include <fstream>
#include <string>
#include <sstream>
#include <bits/chrono.h>

using namespace std;

// 使用C++标准库中的复数类型
using Complex = complex<double>;
using VecComplex = vector<Complex>;

// 递归FFT实现
VecComplex fft(const VecComplex& x) {
    int n = x.size();

    // 基本情况
    if (n == 1) {
        return {x[0]};
    }

    // 检查n是否是2的幂
    if (n & (n - 1)) {
        throw invalid_argument("FFT输入大小必须是2的幂");
    }

    // 分离偶数和奇数索引的元素
    VecComplex even, odd;
    for (int i = 0; i < n; i += 2) {
        even.push_back(x[i]);
        odd.push_back(x[i+1]);
    }

    // 递归计算
    VecComplex even_fft = fft(even);
    VecComplex odd_fft = fft(odd);

    // 合并结果
    VecComplex result(n);
    for (int k = 0; k < n/2; k++) {
        // 计算旋转因子
        Complex w = polar(1.0, -2.0 * numbers::pi * k / n);

        // 蝴蝶操作
        result[k] = even_fft[k] + w * odd_fft[k];
        result[k + n/2] = even_fft[k] - w * odd_fft[k];
    }

    return result;
}

// 计算幅度谱
vector<double> computeMagnitudeSpectrum(const VecComplex& fftResult) {
    vector<double> spectrum(fftResult.size() / 2); // 只取一半，因为对称
    for (size_t i = 0; i < spectrum.size(); i++) {
        spectrum[i] = abs(fftResult[i]);
    }
    return spectrum;
}

// 将频谱数据归一化到0-255范围，用于生成图像
vector<int> normalizeSpectrum(const vector<double>& spectrum) {
    vector<int> normalized(spectrum.size());
    double maxVal = *max_element(spectrum.begin(), spectrum.end());

    for (size_t i = 0; i < spectrum.size(); i++) {
        normalized[i] = static_cast<int>(255 * spectrum[i] / maxVal);
    }

    return normalized;
}

// 生成PPM格式的频谱图
void generateSpectrumImage(const vector<int>& normalizedSpectrum, const string& filename, int height = 256) {
    int width = normalizedSpectrum.size();

    ofstream ppmFile(filename);
    ppmFile << "P3" << endl;
    ppmFile << width << " " << height << endl;
    ppmFile << "255" << endl;

    // 为每个频率分量生成颜色
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // 使用颜色映射：低频为蓝色，中频为绿色，高频为红色
            int intensity = normalizedSpectrum[x];
            int r, g, b;

            // 根据频率位置分配颜色
            double freqRatio = static_cast<double>(x) / width;
            if (freqRatio < 0.33) {
                // 低频：蓝色到青色
                r = 0;
                g = static_cast<int>(intensity * freqRatio * 3);
                b = intensity;
            } else if (freqRatio < 0.66) {
                // 中频：青色到绿色
                r = 0;
                g = intensity;
                b = static_cast<int>(intensity * (1 - (freqRatio - 0.33) * 3));
            } else {
                // 高频：绿色到红色
                r = intensity;
                g = static_cast<int>(intensity * (1 - (freqRatio - 0.66) * 3));
                b = 0;
            }

            ppmFile << r << " " << g << " " << b << " ";
        }
        ppmFile << endl;
    }

    ppmFile.close();
    cout << "频谱图已保存到: " << filename << endl;
}

vector<double> FgetSpectrumPeak(vector<double> amp, double sample_rate, int threshold) {
    // sample_rate == 1 / delta_time
    // amp.size() must be 2^n (int n)
    VecComplex complexSignal;
    int sample_count = amp.size();
    for (double amplitude : amp) {
        complexSignal.emplace_back(amplitude, 0);
    }
    VecComplex freqDomain = fft(complexSignal);
    vector<double> magnitudeSpectrum = computeMagnitudeSpectrum(freqDomain);
    vector<int> normalizedSpectrum = normalizeSpectrum(magnitudeSpectrum);
    vector<double> peaks;
    for (int j = 0; j < normalizedSpectrum.size(); j++) {
        if (normalizedSpectrum[j] > threshold) {
            peaks.push_back(j * sample_rate / sample_count);
        };
    }
    return peaks;
}

// 生成测试信号：多个正弦波的组合
vector<double> generateTestSignal(int sampleCount, double sampleRate) {
    vector<double> signal(sampleCount);

    // 添加多个频率分量
    vector<double> frequencies = {15, 17, 19, 21}; // Hz
    vector<double> amplitudes = {1.0, 1.0, 1.0, 1.0};

    for (int i = 0; i < sampleCount; i++) {
        double t = i / sampleRate;
        signal[i] = 0;

        for (size_t j = 0; j < frequencies.size(); j++) {
            signal[i] += amplitudes[j] * sin(2 * numbers::pi * frequencies[j] * t);
        }

        // 添加一些噪声
        signal[i] += 0.1 * (static_cast<double>(rand()) / RAND_MAX - 0.5);
    }

    return signal;
}