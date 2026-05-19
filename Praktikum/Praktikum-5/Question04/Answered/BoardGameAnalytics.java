import java.util.*;
import java.util.stream.Collectors;

public class BoardGameAnalytics {

    private List<BoardGame> games;
    private Set<String> players;
    private Map<String, Integer> stockByGame;
    private Map<String, List<Integer>> ratings;

    public BoardGameAnalytics() {
        games = new ArrayList<>();
        players = new HashSet<>();
        stockByGame = new HashMap<>();
        ratings = new HashMap<>();
    }

    public void addGame(BoardGame game, int initialStock) {
        if (!games.contains(game)) {
            games.add(game);
        }
        stockByGame.put(game.getName(), stockByGame.getOrDefault(game.getName(), 0) + initialStock);
    }

    public void addRating(String gameName, String playerName, int rating) {
        players.add(playerName);
        ratings.computeIfAbsent(gameName, k -> new ArrayList<>()).add(rating);
    }

    private double getAverageRating(String gameName) {
        List<Integer> gameRatings = ratings.getOrDefault(gameName, Collections.emptyList());
        return gameRatings.stream()
                .mapToInt(Integer::intValue)
                .average()
                .orElse(0.0);
    }

    public List<String> getLowStockGames(int threshold) {
        return stockByGame.entrySet().stream()
                .filter(entry -> entry.getValue() < threshold)
                .sorted((e1, e2) -> {
                    int stockCompare = e1.getValue().compareTo(e2.getValue());
                    if (stockCompare == 0) {
                        return e1.getKey().compareTo(e2.getKey());
                    }
                    return stockCompare;
                })
                .map(Map.Entry::getKey)
                .collect(Collectors.toList());
    }

    public List<String> getRecommendedGames(int playerCount, double minRating) {
        return games.stream()
                .filter(game -> playerCount >= game.getMinPlayers() && playerCount <= game.getMaxPlayers())
                .filter(game -> getAverageRating(game.getName()) >= minRating)
                .map(BoardGame::getName)
                .sorted()
                .collect(Collectors.toList());
    }
}