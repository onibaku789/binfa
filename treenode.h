
/* 
 * File:   treenode.h
 * Author: thedankmemeguy
 *
 * Created on 25 October 2017, 17:01
 */

#ifndef TREENODE_H
#define TREENODE_H
class TreeNode{
private:
    char data;
    char *left_child, *right_child;
    public:
        TreeNode(char init){
            data = init
            left_child = right_child = nullptr;        
        }
        
       Treenode  get_data(){
           return data;
       }
        Treenode *  get_left_child() const {
           return left_child;
       }
        Treenode *  get_right_child() const {
           return right_child;
       }
        
        void set_left_child(Treenode * node){
            left_child = node;
        }
         void set_right_child(Treenode * node){
            right_child = node;
        }

};



#endif /* TREENODE_H */

