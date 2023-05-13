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
#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    int minimumCostPath(vector<vector<int>>& grid)
    {
        int SIDE_SIZE = grid[0].size();
        int SIZE = (int)grid[0].size() * (int)grid.size();
        //bool* visited = new bool[SIZE];
        int** minimumvalues = new int*[SIDE_SIZE];
        for(int i=0;i<SIDE_SIZE;++i)
        {
            minimumvalues[i] = new int[SIDE_SIZE];
            for(int j=0;j<SIDE_SIZE;++j)
            {
                minimumvalues[i][j] = INT_MAX;
            }
        }
        minimumvalues[0][0] = grid[0][0];

        set<pair<int,int>>permutations;
        int position = 0;
        permutations.insert(pair<int,int>(0, grid[0][0]));
        do{
            
            
            pair<int,int>current_position = *permutations.begin();
            position = current_position.first;
            //            if(current_position.second < minimumvalues[position/SIDE_SIZE][position%SIDE_SIZE])
            //            {
            //                permutations.erase(permutations.begin());
            //            } else {
            int x = position/SIDE_SIZE;
            int y = position%SIDE_SIZE;
            //cout << "Current position: " << position << " ";
            //UP
            int new_position = (x-1)*SIDE_SIZE + y;
            if(x-1>=0)
            {
                //cout << " UP Position : " << new_position << " ";
                
                if(minimumvalues[x][y] + grid[x-1][y] < minimumvalues[x-1][y])
                {
                    minimumvalues[x-1][y] = minimumvalues[x][y] + grid[x-1][y];
                    permutations.insert(pair<int,int>(new_position,minimumvalues[x-1][y]));
                }
            }
            //Down
            new_position = (x+1)*SIDE_SIZE + y;
            if(x+1<SIDE_SIZE)
            {
                //cout << " DOWN Position : " << new_position << " ";
                if(minimumvalues[x][y] + grid[x+1][y] < minimumvalues[x+1][y])
                {
                    minimumvalues[x+1][y] = minimumvalues[x][y] + grid[x+1][y];
                    permutations.insert(pair<int,int>(new_position,minimumvalues[x+1][y]));
                }
            }
            
            //Left
            new_position = (x)*SIDE_SIZE + (y+1);
            if(y+1<SIDE_SIZE)
            {
                //cout << " Left Position : " << new_position << " ";
                if(minimumvalues[x][y] + grid[x][y+1] < minimumvalues[x][y+1])
                {
                    minimumvalues[x][y+1] = minimumvalues[x][y] + grid[x][y+1];
                    permutations.insert(pair<int,int>(new_position,minimumvalues[x][y+1]));
                }
            }
            
            //Right
            new_position = (x*SIDE_SIZE) + (y-1);
            if(y-1>=0)
            {
                //cout << " Right Position : " << new_position << " ";
                
                if(minimumvalues[x][y] + grid[x][y-1] < minimumvalues[x][y-1])
                {
                    minimumvalues[x][y-1] = minimumvalues[x][y] + grid[x][y-1];
                    permutations.insert(pair<int,int>(new_position,minimumvalues[x][y-1]));
                }
            }
            permutations.erase(permutations.begin());
            
        //}
            
            
        }while(!permutations.empty());
        
        //cout << minimumvalues[SIDE_SIZE-1][SIDE_SIZE-1] << endl;
        return minimumvalues[SIDE_SIZE-1][SIDE_SIZE-1];
    }
    
    
};

#endif /* Solution_hpp */
