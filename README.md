# edpa-work

Need to implement

Treap
- Insert (long key, long priority)
- Remove (long key)
- Search (long key)
- RotateLeft (pNode grandfather)
- RotateRight (pNode grandfather)

Experiment
- GenerateKeys(unsigned int n_nodes)
- GeneratePriorities(unsigned int n_node)
- InsertBatch (long *keys, long *priorities, unsigned int n_nodes)
- RemoveBatch (long *keys, unsigned int n_nodes)
- SearchBatch (long *keys, unsigned int n_nodes)
- float time_insert[n_nodes]
- float time_remove[n_nodes]
- float time_search[n_nodes]
- SaveTimeData(float * time_insert, float * time_remove, float * time_search, unsigned int n_operation)