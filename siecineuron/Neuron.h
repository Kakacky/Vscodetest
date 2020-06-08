#ifndef ZADANIE1_NEURON_H
#define ZADANIE1_NEURON_H
#include <vector>

class Neuron {
private:
    std::vector<double> weights;
    std::vector<double> deltaWeight;
    double output;
    double layerErrorSignal;
public:
    Neuron() {};

    void randomWeights(int x);

    static double sigmoid(double x);

    void calculateOutput(std::vector<double> in);

    double getOutput();

    double sigmoidDerivative();

    void calculateErrorSignalforLastLayer(double error);

    void calculateErrorSignalforHiddenLayer(const double *errorSignalforLastLayer, double *TW);

    double getErrorSignal();

    double getWeight(int nr);

    void updateWeight(std::vector<double> in);

};


#endif //ZADANIE1_NEURON_H
