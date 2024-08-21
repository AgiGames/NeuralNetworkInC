#include "neuron.h"

struct Neuron* newNeuron(size_t previousLayerSize, size_t nextLayerSize) {
    
    struct Neuron* newNeuron = (struct Neuron* ) malloc(sizeof(struct Neuron));
    newNeuron->previousLayerNeurons = (struct Neuron* ) calloc(previousLayerSize, sizeof(struct Neuron));
    newNeuron->nextLayerNeurons = (struct Neuron* ) calloc(nextLayerSize, sizeof(struct Neuron));
    newNeuron->activation = 0;
    newNeuron->nextLayerNeuronConnectionWeight = 0;
    newNeuron->bias = 0;
    
    return newNeuron;
    
}