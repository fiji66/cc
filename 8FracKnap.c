#include <stdio.h>
#include <stdlib.h>

struct Item { 
    int weight;
    int profit;
    double ratio; 
};

int compareItems(const void* a, const void* b) {
    double ratioA = ((struct Item*)a) -> ratio;
    double ratioB = ((struct Item*)b) -> ratio;
    return (ratioB > ratioA) ? 1 : -1; 
}

void fractionalKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(items[0]), compareItems); // Sort items based on their ratio in non-decreasing order

    int currentWeight = 0; 
    double totalprofit = 0.0; 

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalprofit += items[i].profit;
        } 
        else {
            double fraction = (double)(capacity - currentWeight) / items[i].weight;
            currentWeight = capacity;
            totalprofit += fraction * items[i].profit;
            break;
        }
    }

    printf("Maximum total profit in knapsack = %.2lf\n", totalprofit);
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    struct Item items[n];

    printf("Enter the weight and profit of each item:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    fractionalKnapsack(items, n, capacity);
    return 0;
}