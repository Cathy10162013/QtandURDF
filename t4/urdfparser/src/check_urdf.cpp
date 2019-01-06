/*********************************************************************
* Software License Agreement (BSD License)
*
*  Copyright (c) 2008, Willow Garage, Inc.
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the Willow Garage nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

/* Author: Wim Meeussen */
/* Author: CR 2018.12 */

#include "../include/urdf_parser.h"
#include "../include/check_urdf.h"
#include <iostream>
#include <sstream>
#include <fstream>

#define DEBUG

using namespace urdf;

void printTree(LinkConstSharedPtr link, std::string &res, int level = 0)
{
  std::ostringstream oss;
  level+=2;
  int count = 0;
  for (std::vector<LinkSharedPtr>::const_iterator child = link->child_links.begin(); child != link->child_links.end(); child++)
  {
    if (*child)
    {
      ++count;
#ifdef DEBUG
      for(int j=0; j < level; j++) std::cout << "  "; //indent
      std::cout << "child(" << count << "):  " << (*child)->name  << std::endl;
#endif
      for(int j = 0; j < level ; j++) oss << "  "; //indent
      oss << "child(" << count << "):  " << (*child)->name  << std::endl;
      res += oss.str();
      // first grandchild
      printTree(*child, res, level);
    }
    else
    {
#ifdef DEBUG
      for(int j=0;j<level;j++) std::cout << " "; //indent
      std::cout << "root link: " << link->name << " has a null child!" << *child << std::endl;
#endif
      for(int j=0;j<level;j++) oss << " "; //indent
      oss << "root link: " << link->name << " has a null child!" << *child << std::endl;
      res += oss.str();
    }
  }
}


int check_urdf(std::string file_name, std::string &res)
{
  std::ostringstream oss;
  std::string xml_string;
  std::fstream xml_file(file_name, std::fstream::in);
  while ( xml_file.good() )
  {
    std::string line;
    std::getline( xml_file, line);
    xml_string += (line + "\n");
  }
  xml_file.close();

  ModelInterfaceSharedPtr robot = parseURDF(xml_string);
  if (!robot){
#ifdef DEBUG
    std::cerr << "ERROR: Model Parsing the xml failed" << std::endl;
#endif
    oss << "ERROR: Model Parsing the xml failed" << std::endl;
    res = oss.str();
    return -1;
  }
 #ifdef DEBUG
  std::cout << "robot name is: " << robot->getName() << std::endl;
#endif
  oss << "robot name is: " << robot->getName() << std::endl;
  res = oss.str();

  // get info from parser
  std::cout << "---------- Successfully Parsed XML ---------------" << std::endl;
  // get root link
  LinkConstSharedPtr root_link = robot->getRoot();
  if (!root_link) return -1;
#ifdef DEBUG
  std::cout << "root Link: " << root_link->name << " has " << root_link->child_links.size() << " child(ren)" << std::endl;
#endif
  oss << "root Link: " << root_link->name << " has " << root_link->child_links.size() << " child(ren)" << std::endl;
  res = oss.str();

  // print entire tree
  printTree(root_link, res);
  return 0;
}

