#!/usr/bin/python
import sys, os, commands, time, re, copy

from GenSyntax import *

class YamlData():
  def __init__(self, app_path, options):
    self.app_path = app_path
    self.yaml_data = GenSyntax(app_path, options.recache).GetSyntax()
    
  def recursiveYamlDataSearch(self, path, current_yaml):
    if current_yaml['name'] == path:
      return current_yaml
    else:
      if current_yaml['subblocks']:
        for child in current_yaml['subblocks']:
          yaml_data = self.recursiveYamlDataSearch(path, child)
          
          if yaml_data:  # Found it in a child!
            return yaml_data
      else: # No children.. stop recursion
        return None

  def findYamlEntry(self, path):
    for yaml_it in self.yaml_data:
      yaml_data = self.recursiveYamlDataSearch(path, yaml_it)

      if yaml_data:
        return yaml_data
      
    # This means it wasn't found  
    return None
