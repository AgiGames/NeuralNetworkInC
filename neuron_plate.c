#include "neuron_plate.h"

NeuronPlate* newNeuronPlate(size_t numberOfMiddleLayers, size_t inputLayerSize, size_t middleLayersSize, 
                            size_t outputLayerSize) {
    
    if(numberOfMiddleLayers == 0)
        fprintf(stderr, "Number of middle layers must be greater than 0!");
                                
    NeuronPlate* newNeuronPlate = (NeuronPlate* ) malloc(sizeof(NeuronPlate));
    
    newNeuronPlate->numberOfMiddleLayers = numberOfMiddleLayers;
    newNeuronPlate->inputLayerSize = inputLayerSize;
    newNeuronPlate->outputLayerSize = outputLayerSize;
    newNeuronPlate->middleLayersSize = middleLayersSize;
    
    newNeuronPlate->inputNeurons = (struct Neuron* ) calloc(inputLayerSize, sizeof(struct Neuron));
    
    for(int i = 0; i < inputLayerSize; i++)
        newNeuronPlate->inputNeurons[i] = *(newNeuron(0, middleLayersSize));
        
    newNeuronPlate->outputNeurons = (struct Neuron* ) calloc(outputLayerSize, sizeof(struct Neuron));
    
    for(int i = 0; i < outputLayerSize; i++)
        newNeuronPlate->outputNeurons[i] = *(newNeuron(middleLayersSize, 0));
        
    newNeuronPlate->middleNeurons = (struct Neuron** ) calloc(numberOfMiddleLayers, sizeof(struct Neuron*));
    
    for(int i = 0; i < numberOfMiddleLayers; i++) {
        
        newNeuronPlate->middleNeurons[i] = (struct Neuron* ) calloc(middleLayersSize, sizeof(struct Neuron));
        
        for(int j = 0; j < middleLayersSize; j++) {
            
            if(i == 0)
                newNeuronPlate->middleNeurons[i][j] = *(newNeuron(inputLayerSize, middleLayersSize));
                
            else if(i == numberOfMiddleLayers - 1)
                newNeuronPlate->middleNeurons[i][j] = *(newNeuron(middleLayersSize, outputLayerSize));
                
            else
                newNeuronPlate->middleNeurons[i][j] = *(newNeuron(middleLayersSize, middleLayersSize));
                
        }
    }
    
    /*
     * connect each input neuron to all neurons of first middle layer
     * for each input neuron of the input layer
     * it's next layer connection to each neuron must be completed, where the next layer
     * is the first layer of the middle layers
     */
    for(int i = 0; i < inputLayerSize; i++) {
        for(int j = 0; j < middleLayersSize; j++) {
            newNeuronPlate->inputNeurons[i].nextLayerNeurons[j] = newNeuronPlate->middleNeurons[0][j];
        }
    }
    
    /*
     * connect each neuron of each middle layer to each neuron of next middle layer
     */
    for(int i = 0; i < numberOfMiddleLayers - 1; i++) {
        for(int j = 0; j < middleLayersSize; j++) {
            for(int k = 0; k < middleLayersSize; k++) {
                newNeuronPlate->middleNeurons[i][j].nextLayerNeurons[k] = newNeuronPlate->middleNeurons[i+1][k];
            }
        }
    }
    
    /*
     * connect each neuron of the last middle layer to each neuron of the output layer
     */
    for(int i = 0; i < middleLayersSize; i++) {
        for(int j = 0; j < outputLayerSize; j++) {
            newNeuronPlate->middleNeurons[numberOfMiddleLayers - 1][i].nextLayerNeurons[j] = 
            newNeuronPlate->outputNeurons[j];
        }
    }
    
    return newNeuronPlate;
                                
}