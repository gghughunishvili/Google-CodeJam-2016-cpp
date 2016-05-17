//
//  main.cpp
//  CodeJam
//
//  Created by Giorgi Ghughunishvili on 4/8/16.
//  Copyright © 2016 ggcw. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>

using namespace std;
int main() {
    ifstream fin("inputs/large_input.txt");
    ofstream fout("outputs/large_output.txt");
    int n, C, Item, number_of_items;
    fin>>n;
    // Test Cases for
    for(int i=0; i<n; i++){
        //each store
        vector<int> Items;
        fin>>C>>number_of_items;
        for (int j = 0; j < number_of_items; j++)
        {
            fin>>Item;
            Items.push_back(Item);
        }
        for (int j = 0; j < number_of_items; ++j)
        {
            int x = C - Items[j];
            if (x == Items[j])
            {
                for (int tmp = number_of_items; tmp > j; tmp--)
                {
                    if (x == Items[tmp])
                    {
                        string index_of_i = to_string(i+1);
                        string index_of_j = to_string(j+1);
                        string index_of_pos = to_string(tmp+1);
                        fout<<"Case #"<<index_of_i<<": "<<index_of_j<<" "<<index_of_pos;
                        break;
                    }
                }
            }else{
                int pos = find(Items.begin(), Items.end(), x) - Items.begin();
                if (pos < Items.size())
                {
                    string index_of_i = to_string(i+1);
                    string index_of_j = to_string(j+1);
                    string index_of_pos = to_string(pos+1);
                    fout<<"Case #"<<index_of_i<<": "<<index_of_j<<" "<<index_of_pos;
                    break;
                }
            }
        } 
        if (i<n-1)
        {
            fout<<endl;
        }
    }


    
    return 0;
}
