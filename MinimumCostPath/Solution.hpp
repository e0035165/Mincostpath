//
//  Solution.hpp
//  MinimumCostPath
//
//  Created by Sart Way on 5/5/23.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <fstream>
#include <vector>
#include <queue>
#include <list>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumCostPath(vector<vector<int>>& grid)
    {
        int SIDE_SIZE = grid[0].size();
        int SIZE = (int)grid[0].size() * (int)grid.size();
        bool* visited = new bool[SIZE];
        for(int i=0;i<SIZE;++i)
        {
            visited[i] = false;
        }
        
        queue<pair<int,int>>permutations;
        
        permutations.push(pair<int,int>(0, grid[0][0]));
        int position = 0;
        do{
            pair<int,int>current_position = permutations.front();
            position = current_position.first;
            
            if(position/SIDE_SIZE - 1 >= 0 && visited[(position/SIDE_SIZE - 1)*SIDE_SIZE + position%SIDE_SIZE] == false)
            {
                int new_position = (position/SIDE_SIZE - 1)*SIDE_SIZE + position%SIDE_SIZE;
                int grid_ans = grid[position/SIDE_SIZE - 1][position%SIDE_SIZE];
                pair<int,int>newone(new_position, grid_ans);
            }
            
            visited[position] = true;
            permutations.pop();
        }while(position != SIZE-1);
        return 0;
    }
    
    
};

#endif /* Solution_hpp */
