/* GsTL: the Geostatistics Template Library
 * 
 * Author: Nicolas Remy
 * Copyright (c) 2000 The Board of Trustees of the Leland Stanford Junior University
 * 
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 * 
 *   1.Redistributions of source code must retain the above copyright notice, this 
 *     list of conditions and the following disclaimer. 
 *   2.Redistributions in binary form must reproduce the above copyright notice, this 
 *     list of conditions and the following disclaimer in the documentation and/or other
 *     materials provided with the distribution. 
 *   3.The name of the author may not be used to endorse or promote products derived 
 *     from this software without specific prior written permission. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


template<class U, class Grid>
base_grid_iterator<U, Grid>::base_grid_iterator(Grid* grid, int index, 
						std::string property_name) 
  : index_(index), grid_(grid), g_(grid_, property_name, 0) { 

}




//==================================================
// Sequential iterator

template<class Grid>
sequential_grid_iterator<Grid>::sequential_grid_iterator(Grid* grid,
							 int index,
							 std::string property_name) 
  : base_grid_iterator<sequential_grid_iterator<Grid>,Grid>(grid,
							    index,property_name) {

  init_geovalue();
}

template<class Grid>
void sequential_grid_iterator<Grid>::init_geovalue() {
  this->g_.index() = this->index_;
}



//==================================================
// Random iterator

template<class Grid>
random_grid_iterator<Grid>::random_grid_iterator(Grid* grid,
						 int index,
						 std::string property_name) 
  : base_grid_iterator<random_grid_iterator<Grid>,Grid>(grid,
							index,property_name) {

  init_geovalue();
}

template<class Grid>
void random_grid_iterator<Grid>::init_geovalue() {
  this->g_.index() = this->grid_->random_path_node_index(this->index_);
}



//==================================================
// near data iterator

template<class Grid>
near_data_grid_iterator<Grid>::near_data_grid_iterator(Grid* grid,
						       int index,
						       std::string property_name) 
  : base_grid_iterator<near_data_grid_iterator<Grid>,Grid>(grid,
							   index,property_name) {

  init_geovalue();
}





template<class Grid>
void near_data_grid_iterator<Grid>::init_geovalue() {
  this->g_.index() = this->grid_->near_data_path_node_index(this->index_);
}


#ifdef __GNUC__
#pragma implementation
#endif
#include <GsTL/grid/grid_iterators.h>



