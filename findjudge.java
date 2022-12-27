// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

class findjudge {
    public int findJudge(int n, int[][] trust) {
        int outdegree[] = new int[n+1];
        int indegree[] = new int[n+1];
        int ans = -1;
        for(int i:outdegree)
            i = 0;
        for(int i:indegree)
            i = 0;
        int x[] = new int[2];
        for(int i = 0; i < trust.length; i++) {
            x = trust[i];
            int a = x[0];
            int b = x[1];
            outdegree[a]++;
            indegree[b]++; 
        }
        for(int i:outdegree) {
            System.out.println(i);
        }
        System.out.println();
        for(int i:indegree) {
            System.out.println(i);
        }
        for(int i = 1; i < outdegree.length; i++) {
            if(outdegree[i] == 0 && indegree[i] == n-1) {
                ans = i;
                break;
            }
        }
        return ans;
    }
}