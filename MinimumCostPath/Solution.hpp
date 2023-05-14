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
#include <list>
using namespace std;

class Solution
{
public:
    int minimumCostPath(vector<vector<int>>& grid)
    {
        int SIDE_SIZE = grid[0].size();
        int SIZE = (int)grid[0].size() * (int)grid.size();
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
        
        queue<pair<int,int>>permutations;
        
        permutations.push(pair<int,int>(0, grid[0][0]));
        int position = 0;
        do{
            pair<int,int>current_position = permutations.front();
            position = current_position.first;
            
            int x = position/SIDE_SIZE;
            int y = position%SIDE_SIZE;
            //cout << "Current position: " << position << " ";
            //UP
            if(current_position.second < minimumvalues[position/SIDE_SIZE][position%SIDE_SIZE])
            {
                permutations.pop();
                continue;
            } else {
                int new_position = (x-1)*SIDE_SIZE + y;
                if(x-1>=0)
                {
                    if(minimumvalues[x][y] + grid[x-1][y] < minimumvalues[x-1][y])
                    {
                        minimumvalues[x-1][y] = minimumvalues[x][y] + grid[x-1][y];
                        permutations.push(pair<int,int>(new_position,minimumvalues[x-1][y]));
                    }
                }
                //Down
                new_position = (x+1)*SIDE_SIZE + y;
                if(x+1<SIDE_SIZE)
                {
                    if(minimumvalues[x][y] + grid[x+1][y] < minimumvalues[x+1][y])
                    {
                        minimumvalues[x+1][y] = minimumvalues[x][y] + grid[x+1][y];
                        permutations.push(pair<int,int>(new_position,minimumvalues[x+1][y]));
                    }
                }
                
                //Left
                new_position = (x)*SIDE_SIZE + (y+1);
                if(y+1<SIDE_SIZE)
                {
                    if(minimumvalues[x][y] + grid[x][y+1] < minimumvalues[x][y+1])
                    {
                        permutations.push(pair<int,int>(new_position,minimumvalues[x][y+1]));
                        minimumvalues[x][y+1] = minimumvalues[x][y] + grid[x][y+1];
                    }
                }
                
                //Right
                new_position = (x*SIDE_SIZE) + (y-1);
                if(y-1>=0)
                {
                    if(minimumvalues[x][y] + grid[x][y-1] < minimumvalues[x][y-1])
                    {
                        minimumvalues[x][y-1] = minimumvalues[x][y] + grid[x][y-1];
                        permutations.push(pair<int,int>(new_position, minimumvalues[x][y-1]));
                    }
                }
                permutations.pop();
            }
            
            
        }while(!permutations.empty());
        
        //cout << minimumvalues[SIDE_SIZE-1][SIDE_SIZE-1] << endl;
        return minimumvalues[SIDE_SIZE-1][SIDE_SIZE-1];
    }
    
    long naiveRecursiveMtd(int x, int y, vector<vector<int>>&grid)
    {
        if(x == grid.size() || y == grid[0].size())
        {
            return 0;
        }
        
        if(x < 0 || y < 0)
        {
            return INT_MAX;
        }
        
        long A = grid[x][y] + naiveRecursiveMtd(x-1, y, grid);
        long B = grid[x][y] + naiveRecursiveMtd(x+1, y, grid);
        long C = grid[x][y] + naiveRecursiveMtd(x, y-1, grid);
        long D = grid[x][y] + naiveRecursiveMtd(x, y+1, grid);
        
        long min = A > B ? B : A;
        min = min > C ? C : min;
        min = min > D ? D : min;
        return min;
        
    }
    
};

#endif /* Solution_hpp */
