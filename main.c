#include "neuron_plate.h"

int main() {
    
    NeuronPlate* myNeuronPlate = newNeuronPlate(2, 10, 16, 10);
    free(myNeuronPlate);
    
    return 0;
    
}