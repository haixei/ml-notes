# ROC Curve & AUC
AUC is a success metric used for multi classification problems. It's nothing else than the area under the ROC curve that plots two parameters: **True Positive Rate (y)** and **True Negative Rate (x)**. The curve represents how good the model is at classifying, so for example 0s as 0s and 1s as 1s.

Let's consider a simple binary classification problem. In this case the model's prediction can produce 4 different values:  true positive, false positive, true negative, and false negative. The way we produce a ROC curve is by plotting calculating and plotting TPR against TNR for a single classifier at multiple thresholds. We usually consider that if an observation is predicted as positive at >0.5 probability, it is labelled positive. The curve lets us see how the score behaves at different probabilities, between 0 and 1.

![Binary classification](https://i.imgur.com/sMmIVfv.png)

The true positive rate is a measure of probability that a positive will be labelled correctly. The false positive is a measure of how often a negative instance will get labelled as positive and in vice versa. You can calculate them in a following way:



 ![Equation](https://i.imgur.com/4Nqjx1a.png)





---

### How to interpret the result?

It's very simple to understand the result, the better the model the closer AUC gets to 1. If the model has a value around 0.5, it signalises a poor prediction quality, no better than random guesses. When the value gets close to 0, the model guesses 1s as 0s and 0s as 1s, which is the worst case scenario.



![ROC Plot](https://i.imgur.com/tOjgNKF.png)

---

### Where ROC curves are useful?

Since the ROC curve lets us observe how efficient the model is at classifying at different thresholds, we can use that ability to extract the information about which one of them fits our situation the best. Let's imagine that we took a trip to the forest and want to classify some mushrooms that we picked up as toxic and non-toxic, in this case we want the false positive rate to be even a bit larger. It's better to classify some non toxic shrooms as toxic rather than the other way around. In some other scenarios, we might not want the algorithm to be too aggressive like for example spam classification, if we're not sure if a message should be shown, it's better to do so just in case.

