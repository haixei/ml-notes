# Gradient Boosting-based Models

Gradient Boosting, invented by Jerome Friedman, bases it's accuracy on converting weak learners into strong learners. Each new tree is a fit on a modified version of the original data set. Trees are added one at the time and previous ones get left unchanged. A gradient descent procedure is used to minimize the loss when adding trees.

> After calculating the loss, to perform the gradient descent procedure, we must add a tree to the model that reduces the loss (i.e. follow the gradient). We do this by parameterizing the tree, then modify the parameters of the tree and move in the right direction by (reducing the residual loss.
>
> as said by Jason Brownlee[1]

The output is a tree that gets added to the sequence and the same is repeated until the accuracy doesn't improve anymore.

In short, this is step by step how boosting the tree ensembles works:

1. The first thing we do is calculate the average of the target, and it's our first created leaf.

2. Now we build a new tree based on the errors that the previous tree did, and these errors are the difference between the actual observation and the predicted value. These errors are called the residuals.
3. The new tree is build, **but it won't try to predict the actual values but the residuals.** After it predicts the residual, we can add it to the prediction from the tree before (in our case, look step 1) .
4. Sometimes we could end up in the situation where that actual predicted value from the second tree is super close to the actual value, and it's not very good. It means that we probably have low bias but very big variance. The model is not very good at generalizing and just remembers the output for certain situations it had seen before. The way gradient boosting tackles this is by adding a **learning rate** (a value between 0 and 1) to the equation. Usually we look for the learning rate with a grid search, or by manually selecting it.
5. This sequence of calculating the residual from the new tree and actual value will go on, until the prediction of the actual value will have a small difference from the actual observation.



# The math behind steps

1. We initialize with creating a singular leaf using this equation:
2. 



