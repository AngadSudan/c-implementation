## Creating of Entity DB

```sql
CREATE DATABASE entity;
use entity;
```

## Data Schema of DB

```sql
CREATE TABLE User (
    user_id   INT PRIMARY KEY,
    username  VARCHAR(30) UNIQUE
);

CREATE TABLE Post (
    post_id   INT PRIMARY KEY,
    user_id   INT REFERENCES User(user_id),
    content   VARCHAR(280)
);

CREATE TABLE Comment (
    comment_id INT PRIMARY KEY,
    post_id    INT REFERENCES Post(post_id),
    user_id    INT REFERENCES User(user_id),
    text       VARCHAR(200)
);

CREATE TABLE Like (
    user_id INT REFERENCES User(user_id),
    post_id INT REFERENCES Post(post_id),
    PRIMARY KEY (user_id, post_id)
);

CREATE TABLE Follow (
    follower_id  INT REFERENCES User(user_id),
    following_id INT REFERENCES User(user_id),
    PRIMARY KEY (follower_id, following_id)
);

CREATE TABLE Hashtag (
    hashtag_id INT PRIMARY KEY,
    tag_name   VARCHAR(30)
);

CREATE TABLE PostHashtag (
    post_id    INT REFERENCES Post(post_id),
    hashtag_id INT REFERENCES Hashtag(hashtag_id),
    PRIMARY KEY (post_id, hashtag_id)
);

CREATE TABLE Message (
    message_id  INT PRIMARY KEY,
    sender_id   INT REFERENCES User(user_id),
    receiver_id INT REFERENCES User(user_id),
    sent_at     DATETIME
);
```

## Populate Entity DB

The data to be populated in the entity db

```sql
INSERT INTO `User` (user_id, username) VALUES
(1, 'aarav'),
(2, 'diya'),
(3, 'kabir'),
(4, 'meera');

INSERT INTO Post (post_id, user_id, content) VALUES
(101, 1, 'Hello world'),
(102, 1, 'Second post'),
(103, 2, 'My trip #travel #fun');

INSERT INTO `Like` (user_id, post_id) VALUES
(2, 101),
(3, 101),
(4, 101),
(2, 102);

INSERT INTO Follow (follower_id, following_id) VALUES
(2, 1),
(3, 1),
(4, 1),
(1, 2);

INSERT INTO Hashtag (hashtag_id, tag_name) VALUES
(1, 'travel'),
(2, 'fun'),
(3, 'food');

INSERT INTO PostHashtag (post_id, hashtag_id) VALUES
(103, 1),
(103, 2);
```

## Followers of Aarav

```sql
SELECT count(*) FROM Follow
    WHERE following_id = 1;
```

## Likes on Post 101

```sql
SELECT COUNT(*) FROM `Like`
    WHERE post_id=101;
```

## Hashtags on Post 103

```sql
SELECT COUNT(*) FROM PostHashtag
    WHERE post_id=103;
```

## Creator of Post 102

```sql
SELECT *
FROM (
    SELECT
        u.username,
        p.post_id
    FROM User u
    JOIN Post p
        ON u.user_id = p.user_id
) AS UserPosts
WHERE post_id = 102;
```
