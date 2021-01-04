""" Node is defined as
class node:
  def __init__(self, data):
      self.data = data
      self.left = None
      self.right = None
"""
def inorder_recurse(root, max_data):
    boolean = True
    if root.left: 
        boolean, max_data = inorder_recurse(root.left, max_data)
    if max_data is not None and ((not boolean) or root.data < max_data): return False, max_data
    max_data = root.data
    if root.right: 
        boolean, max_data = inorder_recurse(root.right, max_data)
    return boolean, max_data
    

def check_binary_search_tree_(root):
    if root is None: return True
    return inorder_recurse(root, None)[0]
