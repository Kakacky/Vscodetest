#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <time.h>
#include "Neuron.h"
#include "gnuplot_i.hpp"

#define GNUPLOT_PATH "C:\\gnuplot\\bin"

using namespace std;

int main(){
    int hidden;
    srand(time(nullptr));

    vector<vector<double>> allInputs;
    vector<double> inputData;

    ifstream fin;
    fin.open(R"(C:\Users\User\Desktop\visualcpp\siecineuron\input.txt)");
    double x;
    int p=1;
    while(fin >> x)
    {
        inputData.push_back(x);
        if(p%4 == 0)

        {
            allInputs.push_back(inputData);
            inputData.clear();
        }
        p++;
    }
    fin.close();
    cout<<"Input file"<<endl;
    for (const auto& pom : allInputs)
    {
        for (double j : pom)
            cout << j;
        cout << endl;
    }

    bool bias;
    cout << "Neurons: [1-4]" << endl;
    cin >> hidden;
    cout << "Bias? (0/1)" << endl;
    cin >> bias;

    int outputSize = hidden;

    if(bias == 1)
    {
        for(auto & allInput : allInputs)
            allInput.push_back(1.0);
        outputSize++;
    }

    Neuron layer1 [hidden];
    Neuron layer2 [4];

    for(int i=0; i < hidden; i++)
    {
        Neuron n;
        n.randomWeights(allInputs[0].size());
        layer1[i] = n;
    }

    for(auto & i : layer2)
    {
        Neuron n;
        n.randomWeights(outputSize);
        i = n;
    }

    vector<double> errorsPlot;
    vector<double> epochsPlot;

    int epoch = 1000;

    for(int e=0; e<epoch; e++)
    {

        double epochError = 0;

        random_shuffle(allInputs.begin(), allInputs.end());

        for(const auto & allInput : allInputs)
        {

            vector<double> outputs;
            vector<double> expectedValues;
            double errors[4];
            double avgError = 0;
            double errorSignalforLastLayer[4];

            expectedValues = allInput;
            if(bias == 1)
                expectedValues.erase(expectedValues.end() - 1);

            for(int i=0; i < hidden; i++)
            {
                layer1[i].calculateOutput(allInput);
                outputs.push_back(layer1[i].getOutput());
            }

            if(bias == 1)
            {
                outputs.push_back(1.0);
            }

            for(int i=0; i<4; i++)
            {
                layer2[i].calculateOutput(outputs);
                errors[i] = layer2[i].getOutput() - expectedValues[i];
                layer2[i].calculateErrorSignalforLastLayer(errors[i]);
                errorSignalforLastLayer[i] = layer2[i].getErrorSignal();
            }

            for(int i = 0; i < hidden; i++)
            {
                double tempWeights[4];
                for(int w=0; w<4; w++)
                {
                    tempWeights[w] = layer2[w].getWeight(i);
                }
                layer1[i].calculateErrorSignalforHiddenLayer(errorSignalforLastLayer, tempWeights);
            }

            for(auto & i : layer2)
                i.updateWeight(outputs);

            for(int i=0; i < hidden; i++)
                layer1[i].updateWeight(allInput);

            for(double error : errors)
                avgError += pow(error, 2);
            avgError /= 2;
            epochError += avgError;

            if(e == epoch-1)
            {
                for(int i=0; i < expectedValues.size(); i++)
                {
                    cout << endl;
                    cout << expectedValues[i] << " ";
                    cout << layer2[i].getOutput();
                }
                cout << endl;
            }
        }

        epochError /= 4;
        cout << "Error: " << epochError << endl;

        errorsPlot.push_back(epochError);
        epochsPlot.push_back(e);
    }


    Gnuplot::set_GNUPlotPath(GNUPLOT_PATH);
    Gnuplot main_plot;
    main_plot.set_title( "Error" );
    main_plot.set_xlabel( "X-axis" );
    main_plot.set_ylabel( "Y-axis" );
    main_plot.set_grid();
    main_plot.set_xrange(0, 1000);
    main_plot.set_yrange(0, 1);
    main_plot.set_style("lines");
    main_plot.plot_xy(epochsPlot, errorsPlot, "Error");
    cout <<"Press any button" << endl;
    getchar();
    getchar();

    return 0;
}