
/* 
 * File:   treenode.hpp
 * Author: Attila Varga
 *
 * Created on 25 October 2017, 17:01
 */

#ifndef TREENODE_HPP
#define TREENODE_HPP
class TreeNode{
private:
    char data;
    TreeNode *left_child_charptr, *right_child_charptr;
    
public:
        TreeNode(char init_char){
            data = init_char;
            left_child_charptr = right_child_charptr = nullptr;        
        }
        
        char  get_data(){
           return data;
       }
        TreeNode*  get_left_child() const {
           return left_child_charptr;
       }
        TreeNode*  get_right_child() const {
           return right_child_charptr;
       }
        
        void set_left_child(TreeNode * node){
            left_child_charptr = node;
        }
        void set_right_child(TreeNode * node){
            right_child_charptr = node;
        }
        bool HasChild() {
	return (right_child_charptr != nullptr) || ( left_child_charptr != nullptr);
		}

};



#endif /* TREENODE_HPP */

