#include <stdlib.h>
#include <stdio.h>

struct Neuron{
    
    double activation;
    double bias;
    struct Neuron* previousLayerNeurons;
    struct Neuron* nextLayerNeurons;
    double nextLayerNeuronConnectionWeight;
    
};

struct Neuron* newNeuron(size_t previousLayerSize, size_t nextLayerSize);