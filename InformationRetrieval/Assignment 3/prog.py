import graphlab

ratingDict = {}
userIds = []
itemIds = []
ratings = []

fil = open("u.data")

for line in fil:
	words = line.split()
	userIds.append(words[0])
	itemIds.append(words[1])
	ratings.append(int(words[2]))

ratingDict = {'user_id': userIds,
              'item_id': itemIds,
              'rating': ratings}

sf = graphlab.SFrame(ratingDict)
m = graphlab.recommender.create(sf, target='rating')

recs = m.recommend(users = [1], k = 12)
#recs.save('Recommendations_BinaryFormat')
#loaded_model = graphlab.load_model('Recommendations_BinaryFormat')
#print loaded_model
#recs = m.recommend()
print recs
recs.export_csv("Final recommendations.csv")

m2 = graphlab.item_similarity_recommender.create(sf, target="rating", similarity_type='cosine')
recsm2 = m2.recommend(users = [1], k = 12)
print recsm2
recsm2.export_csv("Final recommendations2.csv")

m3 = graphlab.factorization_recommender.create(sf, target='rating')
recsm3 = m3.recommend(users = [1], k = 12)
print recsm3
recsm3.export_csv("Final recommendations3.csv")

m4 = graphlab.popularity_recommender.create(sf, target='rating')
recsm4 = m4.recommend(users = [1], k = 12)
print recsm4
recsm4.export_csv("Final recommendations4.csv")