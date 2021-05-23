# Random Forest
**Random forest** is an easy to use supervised machine learning algorithm that usually gives a decent result even without parameter tuning. The way the model works is it produces a large ensemble of trees and lets them vote for the most popular class. The idea is based on the wisdom of crowds, one tree might be going into the wrong direction, ending up with a wrong classification. With the larger number of trees, the probability is smaller. There's also one more very important thing contributing to the effectiveness of it and it's the low correlation between the trees that protects them from individual errors.

The trees are usually trained using the **"bagging"** method which means that the random forest will allow each individual tree to randomly sample from the dataset with replacement, in the end resulting in the creation of different trees.

![Random Forest and decision tree](https://i.imgur.com/2ZWAbPb.png)

## Pros and cons

Random Forest deals very well with classification and overfitting, the latter is often causing issues with models based on for ex. gradient boosting. Methods included in the model like bagging or random subspaces which are made from an ensemble of classifiers, using randomization for diversity were proved to be very efficient. One of the things that might be a slight disadvantage for the model is that when sorting numerical attributes while splitting the node can be very memory size heavy and run significantly slower. [1]

A few things worth keeping in mind when it comes to Random Forest:

- It overcomes the problem of overfitting
- While training the model is less sensitive to outlier data
- Variable importance and accuracy is generated automatically



## Gini Impurity

Used by the CART (classification and regression tree) algorithm for classification trees, Gini Impurity is a measure of how often a randomly chosen element from the set would be incorrectly labelled if it was randomly labelled according to the distribution of labels in the subset. [2] Gini impurity is lower bounded by 0, with 0 occurring if the data set contains only one class.

We calculate the metric using following equation:

![Gini Impurity Equation](https://i.imgur.com/bSzeBie.png)



To make it less difficult, let's look at an example where we calculate the Gini Impurity on a simple, singular tree. Let's say we want to predict if a credit card should be blocked because of a potential fraud, we are then met with a binary classification problem. We have two classes: yes, it is fraud and no, it is not a fraud, and let's say that our sample size is 3 to 4.

We then count the GI like below:

![Gini Impurity counted](https://i.imgur.com/qESifne.png)



What we got as a result means that we've got x% chance that the new data point will be incorrectly classified. Let's look at it this way, we have more no's than yes's, so the probability of mis-classifying is less than 50%. **To summarize, Gini Impurity answers the question: what is the probability that we classify the data point incorrectly?** It gets fired at the every level of the tree that proceeds with a greedy, recursive splitting procedure until it reaches its maximum depth or each node only samples from one class. It reaches its minimum (which is 0, it decreases by level) when all cases in the node fall into a single target category. **In this case a feature with a lower GI is chosen for a split.**



_Quick note: The classic CART algorithm uses the GI for constructing the decision tree_



## Entropy and Information Gain

**Entropy** is used to measure the impurity (or in better words - randomness) of a given data set. For example if we are choosing a ball from a box and there's 100 purple ones, the box has 0 entropy, so it has 0 purity or total purity. It is a maximum value of it, just like in the case of Gini Impurity.[3] 



![Information Gain equation](https://i.imgur.com/KeHffpk.png)



**Information Gain** is the process of looking for the best entropy after splitting the tree. To find the best feature which serves as a root node in the terms of IG, we first take the features and split the dataset along their values. We then subtract the result from the originally created entropy to see how much the splitting of the feature reduced it. That gives us the information gain of a feature and is calculated as: 



![Information Gain equation](https://i.imgur.com/Zj4u6Kp.png)



**The feature with the largest information gain will be used as the root node to begin building the tree.**



## Parameter tuning

Parameter tuning can contribute a lot to the model efficiency, accuracy and help to deal with issues like overfitting. The full list of parameters that can be tuned can be found on Scikit's documentation[4], I will list only the more common ones from the articles analysed. [5] [6]

- **n_estimators/The number of decision trees in the forests** - When we try to build a forest with a large number of trees we create a robust aggregate model with less variance and the cost of a longer training time. Since the Random Forest is well, random, if we decide to have a small number of trees on a dataset with a lot of features, some of them may get used very little if at all. The predictive power  could end up being left out of the model since we are not considering some observations. The Random Trees model doesn't overfit often but it doesn't mean that that the accuracy increases infinitely with the number of trees, at some point it will reach its optimum and stop growing. You can pick this value well by using a grid search or running manual testing on different integers.
- **criterion/The function to measure the quality of a split** - For the Sklearn library we can choose either Gini or Entropy, definitions of which we can see above. We can also use MAE or RMSE for regression.
- **bootstrapping/Whether bootstrap samples are used when building trees** - The samples are just random samples of features used for the training, if not specified the whole data set will be used. The samples are drawn with replacement, known as bootstrapping. It means that some samples will be used multiple times in the same tree. Generally this is set to sqrt(n_features) for classification.
- **max_depth/Maximum depth of the tree** - In an individual tree, a maximum depth that is too large leads to overfitting. The model becomes really accurate on the data it have seen and the opposite occurs when we test it on something new. In other words, a tree like that depends on splits it have seen before and is very weak at generalizing. Even though in the case of Random Forest it rarely occurs, it's still a possibility that we need to keep in mind while creating the model. The parameter doesn't influence that much so we can usually keep it out of the grid search if a reasonable amount is selected.
- **max_features/The number of randomly selected features to consider at each split** - A small value might impact the model in a way that the variance gets reduced but the bias increases. If you're model has good quality data with fewer outliers, the value can be set as small but in the case where there's a lot of noise in the data set you might want to consider a higher value (it gives a bigger chance that a quality feature will be included in the voting). Keep in mind that the latter will increase the variance and come with a slower training speed since there will be more features to test at each node. The best way to find a value is to include the parameter in the grid search.



## Referrals 

- **[1]**  [Random Forests and Decision Trees paper by Jehad Ali, Rehanullah Khan, Nasir Ahmad and Imran Maqsood](https://www.researchgate.net/publication/259235118_Random_Forests_and_Decision_Trees)
- **[2]** [Wikipedia's section of the Gini Impurity](https://en.wikipedia.org/wiki/Decision_tree_learning#Gini_impurity)
- **[3]** [Entropy, Information gain, and Gini Index; the crux of a Decision Tree](https://blog.clairvoyantsoft.com/entropy-information-gain-and-gini-index-the-crux-of-a-decision-tree-99d0cdc699f4)
- **[4]** [Scikit Documentation on Random Forest](https://scikit-learn.org/stable/modules/generated/sklearn.ensemble.RandomForestClassifier.html)
- **[5]** [Random Forest: Hyperparameters and how to fine-tune them](https://towardsdatascience.com/random-forest-hyperparameters-and-how-to-fine-tune-them-17aee785ee0d)
- **[6]** [Hyperparameters and Tuning Strategies for Random Forest by Philipp Probst, Marvin Wright and Anne-Laure Boulesteix](https://www.researchgate.net/publication/324438530_Hyperparameters_and_Tuning_Strategies_for_Random_Forest)

**Good articles on the topic:**

- [An Implementation and Explanation of the Random Forest in Python by Will Koehrsen](https://towardsdatascience.com/an-implementation-and-explanation-of-the-random-forest-in-python-77bf308a9b76)
- [Understanding Random Forest by Tony Yiu](https://towardsdatascience.com/understanding-random-forest-58381e0602d2)

