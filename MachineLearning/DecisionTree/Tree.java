import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class Tree<T> {  //implements Iterable<Tree<T>> {

        public T data;
        public boolean clf;             //Classification
        public Tree<T> parent;
        public List<Tree<T>> children;

        public boolean isRoot() {
                return parent == null;
        }

        public boolean isLeaf() {
                return children.size() == 0;
        }

        public Tree(T data) {
                this.data = data;
                this.children = new LinkedList<Tree<T>>();
        }

        public Tree<T> addChild(T child) {
                Tree<T> childNode = new Tree<T>(child);
                childNode.parent = this;
                this.children.add(childNode);
                //this.registerChildForSearch(childNode);
                return childNode;
        }

        public int getLevel() {
                if (this.isRoot())
                        return 0;
                else
                        return parent.getLevel() + 1;
        }

        
        /*private void registerChildForSearch(Tree<T> node) {
                elementsIndex.add(node);
                if (parent != null)
                        parent.registerChildForSearch(node);
        }

        public Tree<T> findTree(Comparable<T> cmp) {
                for (Tree<T> element : this.elementsIndex) {
                        T elData = element.data;
                        if (cmp.compareTo(elData) == 0)
                                return element;
                }

                return null;
        }

        @Override
        public String toString() {
                return data != null ? data.toString() : "[data null]";
        }

        @Override
        public Iterator<Tree<T>> iterator() {
                TreeIter<T> iter = new TreeIter<T>(this);
                return iter;
        }*/

}

class TreeTestDrive {
        
        public static void preOrderTraversal(Tree<Integer> node) {
                if(node != null) {
                        System.out.println(node.data);
                        for(Tree<Integer> nd : node.children) {
                                preOrderTraversal(nd);
                        }        
                }
        }
        
        public static void main(String ...args) {
                Tree<Integer> root = new Tree<Integer>(2);
                Tree<Integer> child1 = root.addChild(1);
                Tree<Integer> child2 = root.addChild(0);
                Tree<Integer> child11 = child1.addChild(3);
                Tree<Integer> child21 = child2.addChild(4);
                
                preOrderTraversal(root);
        }
}