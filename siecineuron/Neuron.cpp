#include "Neuron.h"
#include <cstdlib>
#include <cmath>

double learningRate = 0.8;
double momentum = 0.7;


void Neuron::randomWeights(int x) {
    for (int i=0; i<x; i++){
        deltaWeight.push_back(0.0);
        weights.push_back(rand()/double(RAND_MAX));
    }
}

double Neuron::sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double Neuron::sigmoidDerivative(){
    return output*(1-output);
}

void Neuron::calculateOutput(std::vector<double> input) {
    double sum = 0;
    for (int i=0; i<weights.size(); i++) {
        sum += weights[i] * input[i];
    }
    output = sigmoid(sum);
}

double Neuron::getOutput(){
    return output;
}

void Neuron::calculateErrorSignalforLastLayer(double error){
    layerErrorSignal = error * sigmoidDerivative();
}

void Neuron::calculateErrorSignalforHiddenLayer(const double *errorSignalforLastLayer, double *weights){
    double s = 0;
    for(int i=0; i<4; i++)
        s += errorSignalforLastLayer[i] * weights[i];
    layerErrorSignal = s * sigmoidDerivative();
}

double Neuron::getErrorSignal(){
    return layerErrorSignal;
}

double Neuron::getWeight(int nr){
    return weights[nr];
}

void Neuron::updateWeight(std::vector<double> in){
    for(int d=0; d<deltaWeight.size(); d++){
        double newDelta = (momentum * deltaWeight[d] - learningRate * layerErrorSignal * in[d]) ;
        deltaWeight[d] = newDelta;
        weights[d] += deltaWeight[d];
    }
}

