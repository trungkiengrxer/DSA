    bool next = false;
    for (int v : adj[u]) {
        if (!visited[v]) {
            next = true;
            break;
        }
    }

    if (!next) return;