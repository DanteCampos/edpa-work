# edpa-work
This work evaluates the Treap data structure in comparison with a Binary Search Tree (BST) and an AVL tree. We measure the time (in milisseconds) spent for each batch of $10^{5}$ operations. We generate $10^{7}$ random nodes to insert, search, and remove from the trees. Our experiment consists of:
- Batchs of inserting $10^{5}$ nodes and then searching the same $10^{5}$ nodes in equal order, until all $10^{7}$ nodes are inserted;
- Batchs of searching $10^{5}$ nodes, until all $10^{7}$ nodes are searched
- Batchs of inserting $10^{5}$ nodes and then searching the same $10^{5}$ nodes in equal order, until all $10^{7}$ nodes are removed.
  
## Running the experiment
Compile `main.c` and execute its binary. The results will be saved in `results.csv`. Then, run `plot_results.py` to generate plots inside `plots/` folder.
