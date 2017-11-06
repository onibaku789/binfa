/* 
 * File:   tree.hpp
 * Author: Attila Varga
 *
 * Created on 27 October 2017, 09:09
 */

#ifndef TREE_HPP
#define TREE_HPP

#include "treenode.hpp"
#include <functional>
#include <iostream>
#include <cmath>
#include <string>
    

class Tree{
public:
    Tree(): root('/'), traverse_depth(0), insertion_depth(0), mean_sum(0),external_nodes(1){
			current_node = &root;
			max_depth = 0;
		}
    ~Tree(){
        FreeNode(root.get_left_child());
        FreeNode(root.get_right_child());
    }
    
    
   void operator<< (char c_char);
   void TraverseTree(TreeNode *node, std::function<void(TreeNode*,int)> fn_l);
   
   double Mean(void);
   double Variance(void);
   
   friend std::ostream & operator<< (std::ostream &out_stream, Tree &Tree);
   
   
   TreeNode* get_root_node() {
        return &root;
	}
   int get_max_depth(void) {
	return max_depth;
	}
   int get_external_nodes(void) {
	return external_nodes;
	}
protected:
    void Print(TreeNode* node);
private:
        TreeNode root;
        TreeNode *current_node;
       					
		int insertion_depth; 		
		int traverse_depth;		
		int max_depth;			
		int mean_sum;
		double variance_sum;
                int external_nodes;	
        
        void FreeNode(TreeNode *node);
        Tree (const Tree&);
        Tree& operator= (const Tree&);
        std::function<void(TreeNode*,int)> traverse_function;
    
};



#endif /* TREE_HPP */

