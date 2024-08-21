#include "neuron.h"

struct NeuronPlate {
    
    size_t numberOfMiddleLayers;
    size_t inputLayerSize;
    size_t outputLayerSize;
    size_t middleLayersSize;
    
    struct Neuron* inputNeurons;
    struct Neuron* outputNeurons;
    struct Neuron** middleNeurons;
    
};

typedef struct NeuronPlate NeuronPlate;

NeuronPlate* newNeuronPlate(size_t numberOfMiddleLayers, size_t inputLayerSize, size_t middleLayersSize, 
                            size_t outputLayerSize);