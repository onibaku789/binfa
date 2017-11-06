/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "tree.hpp"
void Tree::FreeNode(TreeNode *node){
    if (node != nullptr){
        FreeNode(node->get_right_child());
        FreeNode(node->get_left_child());

        delete node;
    }
}
void Tree::operator<<(char c_char) {
	TreeNode *temp_node = (c_char == '0') ? current_node->get_left_child() : current_node->get_right_child();

	++insertion_depth;

	if (temp_node != nullptr) {
		current_node = temp_node;
	}
	else {
		TreeNode* new_node = new TreeNode (c_char);


		if (current_node->HasChild())
		{
                        external_nodes++;
			mean_sum += insertion_depth;
		}
		else
			++mean_sum;


		if (c_char == '0')
			current_node->set_left_child(new_node);
		else
			current_node->set_right_child(new_node);


		if (insertion_depth > max_depth)
			max_depth = insertion_depth;


		insertion_depth = 0;

	  current_node = &root;
	}
}

void Tree::TraverseTree( TreeNode *node,std::function<void(TreeNode*, int)> fn_l) {
	traverse_depth = 0;

	traverse_function = fn_l;

	Print(node);
}

void Tree::Print(TreeNode *node) {
	if (node == nullptr) {
		return;
	}

	traverse_function(node, traverse_depth);

	++traverse_depth;
	Print(node->get_right_child());
	Print(node->get_left_child());
	--traverse_depth;
}


double Tree::Variance(void)
{
	double avg = Mean();
	double var;

	variance_sum = 0;

	TraverseTree( &root, [&](TreeNode *n, int depth) {
       if (!n->HasChild())
         variance_sum += ((depth - avg) * (depth - avg));
							 });
	if (external_nodes - 1 > 0)
		var = std::sqrt(variance_sum / (external_nodes - 1));
	else
		var = std::sqrt(variance_sum);

	return var;
}

double Tree::Mean(void)
{
	return (double)mean_sum / external_nodes;
}

std::ostream & operator<< (std::ostream &output_stream, Tree &tree) {
	tree.TraverseTree(tree.get_root_node(), [&](TreeNode *n, int depth) {
	 	output_stream << std::string(depth * 3, '-') << n->get_data()
	 	<< '(' << (depth - 1) << ')' << std::endl;
						 });

	return output_stream;
}